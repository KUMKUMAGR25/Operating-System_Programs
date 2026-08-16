#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Enter the number of processes:" ;
    cin>>n;

    int bt[20],wt[20],tat[20],p[20];
    
    //Input burst time

    for(int i = 0; i<n; i++){
        p[i]=i+1;
        cout<<"Enter the burst time fot p"<<p[i]<<":";
        cin>>bt[i];
    }
    //Sort according to burst time
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if (bt[i]>bt[j]){
                swap(bt[i] ,bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    //Calculate waiting time
    wt[0]=0;

    for(int i=1; i<n; i++){
        wt[i] = wt[i-1]+bt[i-1];
    }
    //Calculate turnaround time
    for(int i=0; i<n;i++){
        tat[i] = wt[i] + bt[i];
    }
    //Display results
    cout<<"\nProcess\tBurst time\tWaiting time\tTurnaround time\n";

    float avgWT = 0, avgTAT = 0;

    for(int i=0; i<n; i++){
        cout<<"p"<<p[i]<<"\t"
        <<bt[i]<<"\t\t"
        <<wt[i]<<"\t\t"
        <<tat[i]<<endl;

        avgWT += wt[i];
        avgTAT += tat[i];
    }
    avgWT/=n;
    avgTAT/=n;

    cout<<"\n Average Waiting Time ="<<avgWT;
    cout<<"\nAverage Turnaround Time ="<<avgTAT<<endl;

    return 0;
}