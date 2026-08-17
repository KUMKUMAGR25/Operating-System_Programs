#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;

    int bt[n],wt[n],tat[n];
    float avg_wt = 0, avg_tat = 0;

    cout<<"Enter burst time for each processes:/n";
    for(int i = 0;i<n; i++){
        cout<<"p"<< i+1 <<":";
        cin>>bt[i];
    }
    //FCFS Scheduling
    wt[0] = 0; //First process has zero waiting time
    for(int i =1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
    //Calculate turnaround time
    for(int i = 0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    cout<<"\nProcess\tBurst time\tWaiting time\t Turnaround time\n";
    for(int i=0; i<n; i++){
        cout<<"P"<<i+1<<"\t"
        <<bt[i]<<"\t\t"
        <<wt[i]<<"\t\t"
        <<tat[i]<<endl;
    }
    cout<<"\n Average waiting time ="<<avg_wt<<endl;

    cout<<"\n Average Turnaround time ="<<avg_tat<<endl;

    return 0;
}