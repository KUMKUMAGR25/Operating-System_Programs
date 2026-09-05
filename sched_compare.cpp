#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    int id, bt, priority;
};

// FCFS
void FCFS(Process p[], int n) {
    int wt[20] = {}, tat[20] = {};
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + p[i - 1].bt;

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + p[i].bt;

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nFCFS";
    cout << "\nAverage Waiting Time: " << avgWT / n;
    cout << "\nAverage Turnaround Time: " << avgTAT / n << endl;
}

// SJF
void SJF(Process p[], int n) {
    Process temp[20];

    for (int i = 0; i < n; i++)
        temp[i] = p[i];

    sort(temp, temp + n, [](Process a, Process b) {
        return a.bt < b.bt;
    });

    int wt[20] = {}, tat[20] = {};

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + temp[i - 1].bt;

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + temp[i].bt;

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nSJF";
    cout << "\nAverage Waiting Time: " << avgWT / n;
    cout << "\nAverage Turnaround Time: " << avgTAT / n << endl;
}

// Priority Scheduling
void PriorityScheduling(Process p[], int n) {
    Process temp[20];

    for (int i = 0; i < n; i++)
        temp[i] = p[i];

    // Smaller priority number = higher priority
    sort(temp, temp + n, [](Process a, Process b) {
        return a.priority < b.priority;
    });

    int wt[20] = {}, tat[20] = {};

    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + temp[i - 1].bt;

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + temp[i].bt;

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nPriority Scheduling";
    cout << "\nAverage Waiting Time: " << avgWT / n;
    cout << "\nAverage Turnaround Time: " << avgTAT / n << endl;
}

// Round Robin
void RoundRobin(Process p[], int n, int quantum) {
    int remBT[20];

    for (int i = 0; i < n; i++)
        remBT[i] = p[i].bt;

    int wt[20] = {}, tat[20] = {};
    int time = 0;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (remBT[i] > 0) {
                done = false;

                if (remBT[i] > quantum) {
                    time += quantum;
                    remBT[i] -= quantum;
                } else {
                    time += remBT[i];
                    wt[i] = time - p[i].bt;
                    remBT[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = p[i].bt + wt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nRound Robin";
    cout << "\nAverage Waiting Time: " << avgWT / n;
    cout << "\nAverage Turnaround Time: " << avgTAT / n << endl;
}

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    Process p[20];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        cout << "\nEnter Burst Time for P" << i + 1 << ": ";
        cin >> p[i].bt;

        cout << "Enter Priority for P" << i + 1 << ": ";
        cin >> p[i].priority;
    }

    cout << "\nEnter Time Quantum for Round Robin: ";
    cin >> quantum;

    cout << "\n========== CPU SCHEDULING COMPARISON ==========\n";

    FCFS(p, n);
    SJF(p, n);
    PriorityScheduling(p, n);
    RoundRobin(p, n, quantum);

    return 0;
}