#include<iostream> 
using namespace std; 
  



void FwaitingTime(int processes[], int n,  
                          int bt[], int wait[]) 
{ 
    
    wait[0] = 0; 
  
    for (int  k = 1; k < n ; k++ ) 
        wait[k] =  bt[k-1] + wait[k-1] ; 
} 

void TurnAroundT( int processes[], int n,  
                  int bt[], int wait[], int tat[]) 
{ 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wait[i]; 
} 
  
void findAverageTime( int process[], int n, int bt[]) 
{ 
    int wait[n], tat[n], total_wait = 0, total_tat = 0; 
    FwaitingTime(process, n, bt, wait); 
    TurnAroundT(process, n, bt, wait, tat); 
  
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n"; 
  
    for (int  k=0; k<n; k++) 
    { 
        total_wait = total_wait + wait[k]; 
        total_tat = total_tat + tat[k]; 
        cout << "   " << k+1 << "\t" << bt[k] <<"\t    "
            << wait[k] <<"\t " << tat[k] <<endl; 
    } 
  float us1=(float)total_wait / (float)n; 
  float us2 = (float)total_tat / (float)n; 
    cout << "Average waiting time = "   << us1;
    cout << "\nAverage turn around time = "  << us2;
} 
int main() 
{
    int process[] = { 1, 2, 3}; 
    int n = sizeof process / sizeof process[0]; 
    int  burst_time[] = {13, 4 ,9}; 
    //find avrage tym
    findAverageTime(process, n,  burst_time); 
    return 0; 
} 
