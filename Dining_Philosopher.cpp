#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex fork1, fork2, fork3, fork4, fork5;

void philosopher(int id, mutex& left, mutex& right) {
    left.lock();
    right.lock();

    cout << "Philosopher " << id << " is eating\n";

    right.unlock();
    left.unlock();

    cout << "Philosopher " << id << " is thinking\n";
}

int main() {
    thread t1(philosopher, 1, ref(fork1), ref(fork2));
    thread t2(philosopher, 2, ref(fork2), ref(fork3));
    thread t3(philosopher, 3, ref(fork3), ref(fork4));
    thread t4(philosopher, 4, ref(fork4), ref(fork5));
    thread t5(philosopher, 5, ref(fork5), ref(fork1));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}