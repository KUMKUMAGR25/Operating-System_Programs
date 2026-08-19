#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n, tq;

    cout << "Enter the number of processes:";
    cin >> n;

    int bt[n],rem_bt[n],wt[n] = {0},tat[n];

    cout << "Enter burst time for each process:\n";
    for(int i = 0; i < n; i++){
        cout << "P" << i+1 << ":";
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }

    cout << "Enter time quantum:";
    cin >> tq;

    int time= 0;
    //Round Robin Scheduling
    while(true){
        bool done = true;

        for(int i = 0; i<n; i++){
            if (rem_bt[i] > 0){
                done = false;

                if (rem_bt[i] > tq){
                    time += tq;
                    rem_bt[i] -= tq;
                } 
                else{
                    time += rem_bt[i];

                    //Completion time  = Turnaround time
                    tat[i] = time;

                    //Waiting time = Turnaround time - burst time
                    wt[i] = tat[i] - bt[i];

                    rem_bt[i] = 0;
                }
            }
        }

        if(done)
            break;
    }    

        float avg_wt = 0, avg_tat = 0;

        cout << "\nProcess\tBurst time\tWaiting time\tTurnaround time\n";
        for(int i = 0; i<n; i++){
            avg_wt += wt[i];
            avg_tat += tat[i];

            cout << "P" << i+1 << "\t"
            << bt[i]<< "\t\t"
            << wt[i] << "\t\t"
            << tat[i] << endl;
        }
        avg_wt /= n;
        avg_tat /= n;
        cout << fixed << setprecision(2);
        cout << "\nAverage Waiting time =" << avg_wt << endl;
        cout << "\nAverage Turnaround time = "<< avg_tat <<endl;

        return 0;
    }