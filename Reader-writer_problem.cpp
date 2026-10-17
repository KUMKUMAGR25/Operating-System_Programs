#include <iostream>
#include <pthread.h>
using namespace std;

int data = 0;
int readers = 0;

pthread_mutex_t mutex;
pthread_mutex_t writeLock;

void* reader(void*) {
    pthread_mutex_lock(&mutex);
    readers++;

    if (readers == 1)
        pthread_mutex_lock(&writeLock);

    pthread_mutex_unlock(&mutex);

    cout << "Reader reads: " << data << endl;

    pthread_mutex_lock(&mutex);
    readers--;

    if (readers == 0)
        pthread_mutex_unlock(&writeLock);

    pthread_mutex_unlock(&mutex);

    return nullptr;
}

void* writer(void*) {
    pthread_mutex_lock(&writeLock);

    data++;
    cout << "Writer writes: " << data << endl;

    pthread_mutex_unlock(&writeLock);
    return nullptr;
}

int main() {
    pthread_t r1, r2, w1;

    pthread_mutex_init(&mutex, nullptr);
    pthread_mutex_init(&writeLock, nullptr);

    pthread_create(&r1, nullptr, reader, nullptr);
    pthread_create(&w1, nullptr, writer, nullptr);
    pthread_create(&r2, nullptr, reader, nullptr);

    pthread_join(r1, nullptr);
    pthread_join(w1, nullptr);
    pthread_join(r2, nullptr);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&writeLock);

    return 0;
}