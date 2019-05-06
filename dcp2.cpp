#include<bits/stdc++.h> 
                                      // increasing short j f 
using namespace std;                  
struct process 
{ 
   int prid;  
   int btt;  
}; 

bool compared(process h, process kbnn) 
{ 
     return (h.btt < kbnn.btt); 
} 
void waitnigTimeToBeFound(process pro[], int number, int wait[]) 
{  
    wait[0] = 0; //first procs 
    for (int i = 1; i < number ; i++ ) 
        wait[i] = pro[i-1].btt + wait[i-1] ; 
} 
void turnAroundtimeToBFound(process pro[], int number, int wait[], int tt[]) 
{ 
    
    for (int i = 0; i < number ; i++) 
    tt[i] = pro[i].btt + wait[i]; 
} 
  
void avgtime(process pro[], int number) 
{ 
    int wait[number], tt[number], total_wait = 0, total_tt = 0; 
  
    
    waitnigTimeToBeFound(pro, number, wait);  
    turnAroundtimeToBFound(pro, number, wait, tt); 
    cout << "\n  hamaray procses "<<endl;
	cout<< "  inn ka Burst time "<<endl;
	cout<< "this is Waiting time " <<endl;
	cout<< "ye ha Turn around time\n"; 
    for (int i = 0; i < number; i++) 
    { 
        total_wait = total_wait + wait[i]; 
        total_tt = total_tt + tt[i]; 
        cout << "    " << pro[i].prid << " "<< "\t\t"<< pro[i].btt << "\t " << wait[i] << "\t\t " << tt[i] <<endl; 
    } 
    cout << "Avg waiting time = "<< (float)total_wait / (float)number; 
    cout << "\nAvge turn around time = "<< (float)total_tt / (float)number; 
} 
   
int main() 
{ 
    process pro[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}}; 
    cout<<" ";
    int number = sizeof pro / sizeof pro[0]; 
    sort(pro, pro + number, compared); // Sorting procses by burst time. 
  
    cout << "procs ka execution order\n"; 
    for (int i = 0 ; i < number; i++) 
        cout << pro[i].prid <<" "; 
    avgtime(pro, number); 
    return 0; 
}
