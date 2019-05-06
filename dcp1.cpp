#include<iostream>
using namespace std;
int Z;//Num of Processes
int C;//Num of resourse
int sequence[20];
int allocat[20][20],
RNN[20][20],
available[20];
int cd;

void getdata()//get data from user
{
	 cout<<"Enter Number of Processes  : ";
	 
    cin>>Z;
    
    cout<<"Enter Number of resourse : ";
    
    cin>>C;
    
    cout<<" Enter number of instances available of each resource : ";
    for(int i=0;i<C;i++)
        cin>>available[i];
    for(int i=0;i<Z;i++)
    {
        cout<<" number of instances of resources allocatocated  p["<<i<<"] : ";
        for(int y=0;y<C;y++)
            cin>>allocat[i][y];
    }
    for(int i=0;i<Z;i++)
    {
        cout<<"maximum number of instances of resources process p["<<i<<"] needs : ";
        for(int y=0;y<C;y++)
            cin>>RNN[i][y];
    }
}

int com_pr()
{
	 int flag=0;
	 int fl=0;
    for(int i=0;i<Z;i++)
    {
        for(int j=0;j<cd;j++)
            if(Z==sequence[j])
            {
                fl=1;
                break;
            }
        if(fl!=1)
        {
            for(int j=0;j<C;j++)
            {
                if(available[j]-RNN[Z][j]+allocat[Z][j]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return Z;
            flag=0;
        }
        fl=0;
    }
    return -1;
}
void safe_sequence()
{
    int temp,flag=0;
    cd=0;
    for(int i=0;i<Z;i++)
    {
        temp=com_pr();
        if(temp!=-1)
        {
            for(int y=0;y<C;y++)
                available[y]+=allocat[temp][y];
            sequence[cd++]=temp;
        }
        else{
            cout<<"\n  System in  unsafe state  ";
            flag=1;
            break;}
    }
    if(flag!=1)
    {
        cout<<"     Safe sequence created : ";
        for(int i=0;i<cd;i++)
            cout<<"p["<<sequence[i]<<"]  ";
    }
}

int main()
{
    getdata();
    safe_sequence();
    return 0;
}
