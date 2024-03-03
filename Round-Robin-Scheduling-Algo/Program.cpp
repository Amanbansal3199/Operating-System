#include <iostream>
using namespace std;

void CalWaitTime(int TQ, int BT[], int p[], int n, int Wt_time[]){

    int rem_BT[n]; // will store the remaining brust time after each process execution

    for(int i=0; i<n; i++){
        rem_BT[i] = BT[i];
    }

    int Curr_time = 0; 

    while(1){

        bool Executed = true;

        for(int i=0; i<n; i++){

            if(rem_BT[i]>0){
                Executed = false;


                if(rem_BT[i]>TQ){
                    Curr_time+=TQ;
                    rem_BT[i]-=TQ;
                }
                else{
                    Curr_time+=rem_BT[i];
                    Wt_time[i] = Curr_time -  BT[i];  // waiting time = completing time - Brust time
                    rem_BT[i] = 0;
                }
            }
        }

        if (Executed == true){
            break;
        }
    }


}

void CalTat(int BT[], int TAT[], int Wt_time[],int n){

    for(int i=0; i<n; i++){
        TAT[i] = BT[i] + Wt_time[i];
    }
}

int CalculateAverageTime(int TQ, int BT[], int P[],int n){

    // Calculating weighting Time for each Processes

    int Wt_time[n];

    CalWaitTime(TQ,BT,P,n,Wt_time);

    // Calculating Trun around time

    int TAT[n];

    int Total_wt = 0;
    int Total_Tat = 0;

    CalTat(BT,TAT,Wt_time, n);

        cout<<"Process No."<<"  Brust Time"<<"  Wait_Time"<<"  "<<" TAT"<<endl;

    for(int i=0; i<n; i++){

        Total_Tat+=TAT[i];
        Total_wt+=Wt_time[i];
        cout<<i+1<<"\t\t"<<"         "<<BT[i]<<"\t\t"<<"   "<<Wt_time[i]<<"\t\t"<<"  "<<TAT[i]<<endl;

    }

    cout<<"Average_Wt_Time="
        <<(float)Total_wt/n<<endl;
    cout<<"Average_TAT="
        <<(float)Total_Tat/n;

}

int main(){
    // int TimeQuant=0;
    // int n;
    // int Processes[n];
    // int BrustTime[n];

    // cout<<"Enter Number of Process-";
    // cin>>n;

    // cout<<"Enter Process-";
    // for(int i=0; i<n; i++){
    //     cin>>Processes[i];
    // }

    // cout<<"Enter Brust Time for each Process";
    // for(int i=0; i<n; i++){
    //     cin>>BrustTime[i];
    // }

    // cout<<"Enter Time Quantam-";
    // cin>>TimeQuant;
    int n = 4;
    int Processes[] = {1,2,3,4};
    int BrustTime[]= {10,11,8,9};
    int TimeQuant = 3;


    CalculateAverageTime(TimeQuant,BrustTime,Processes,n);


}