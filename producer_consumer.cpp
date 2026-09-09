#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

using namespace std;

#define SIZE 5

struct SharedData
{
    int buffer[SIZE];
    int in;
    int out;
};

// Wait operation
void waitSem(int semid, int semNum)
{
    struct sembuf op = {(unsigned short)semNum, -1, 0};
    semop(semid, &op, 1);
}

// Signal operation
void signalSem(int semid, int semNum)
{
    struct sembuf op = {(unsigned short)semNum, 1, 0};
    semop(semid, &op, 1);
}

int main()
{
    // Create shared memory
    int shmid = shmget(IPC_PRIVATE, sizeof(SharedData),
                       IPC_CREAT | 0666);

    SharedData *data = (SharedData *)shmat(shmid, NULL, 0);

    data->in = 0;
    data->out = 0;

    // Create 3 semaphores
    // 0 = Empty, 1 = Full, 2 = Mutex

    int semid = semget(IPC_PRIVATE, 3, IPC_CREAT | 0666);

    semctl(semid, 0, SETVAL, SIZE);
    semctl(semid, 1, SETVAL, 0);
    semctl(semid, 2, SETVAL, 1);

    // Create producer process
    pid_t producer = fork();

    if (producer == 0)
    {
        // Producer
        for (int i = 1; i <= 10; i++)
        {
            waitSem(semid, 0);
            waitSem(semid, 2);

            data->buffer[data->in] = i;

            cout << "Producer produced: "
                 << i << endl;

            data->in = (data->in + 1) % SIZE;

            signalSem(semid, 2);
            signalSem(semid, 1);

            sleep(1);
        }

        shmdt(data);
        return 0;
    }

    // Create consumer process
    pid_t consumer = fork();

    if (consumer == 0)
    {
        // Consumer
        for (int i = 1; i <= 10; i++)
        {
            waitSem(semid, 1);
            waitSem(semid, 2);

            int item = data->buffer[data->out];

            cout << "Consumer consumed: "
                 << item << endl;

            data->out = (data->out + 1) % SIZE;

            signalSem(semid, 2);
            signalSem(semid, 0);

            sleep(2);
        }

        shmdt(data);
        return 0;
    }

    // Parent waits for both processes
    wait(NULL);
    wait(NULL);

    // Detach shared memory
    shmdt(data);

    // Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);

    // Remove semaphore
    semctl(semid, 0, IPC_RMID);

    cout << "\nProducer-Consumer problem completed." << endl;

    return 0;
}