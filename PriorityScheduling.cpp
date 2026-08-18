#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter number of processes:";
    cin >> n;

    int p[20], bt[20], priority[20];
    int wt[20],tat[20];

    //input 
    for(int i = 0; i<n; i++){
        p[i] = i+1;
        cout<<" Enter burst time for p" <<p[i]<<":";
        cin >> bt[i];

        cout << "Enter priority for p" << p[i]<<":";
        cin >> priority[i];
    }

    // Sort according to priority 
    //Smaller priority number = higher priority

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(priority [i] > priority [j]){
                swap(priority[i], priority[j]);
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
            }
        }
    }

    //Calculate waiting time
    wt[0] = 0;

    for(int i = 0; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    //Calculate turnaround time
    for(int i = 0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }

    //Display results

    cout << "\nProcess\tBurst Time\tPriority\tWaiting time\tTurnaround Time\n";

    float avg_WT=0, avg_TAT = 0;

    for(int i = 0; i<n; i++){
        cout<< "P" << p[i]<<"\t"
        <<bt[i]<<"\t\t"
        <<priority[i] << "\t\t"
        <<wt[i] << "\t\t"
        <<tat[i]<< endl;

        avg_WT += wt[i];
        avg_TAT += tat[i];
    }

    avg_WT /= n;
    avg_TAT /= n;
    cout << "\nAverage waiting time = "<< avg_WT;
    cout << "\nAverage Turnaround time = "<< avg_TAT<< endl;

    return 0;

}