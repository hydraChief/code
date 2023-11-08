#include<bits/stdc++.h>
using namespace std;

struct Process{
    int id,at,bt,pr;
};

bool comp(Process a, Process b){
    if(a.at==b.at) return a.pr>b.pr;
    return a.at<b.at;
}
int main(){
    vector<Process> p={{1,2,3,3},{2,1,5,4},{3,3,1,1},{4,4,7,7},{5,5,4,8}};
    sort(p.begin(),p.end(),comp);

    int n=p.size();
    vector<int> st(n),wt(n),tot(n),ct(n);
    st[0]=p[0].at;
    wt[0]=0;
    for(int i=1;i<n;i++){
        st[i]=st[i-1]+p[i-1].bt;
        wt[i]=max(st[i]-p[i].at,0);
    }

    for(int i=0;i<n;i++){
        ct[i]=st[i]+p[i].bt;
        tot[i]=wt[i]+p[i].bt;
    }

    float wavg=0,tavg=0;
    
    cout<<"Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time"<<endl;

    for(int i=0;i<n;i++)
    {
        wavg += wt[i];
        tavg += tot[i];
        
        cout<<p[i].id<<"\t\t"<<
            st[i]<<"\t\t"<<ct[i]<<"\t\t"<<
            tot[i]<<"\t\t\t"<<wt[i]<<endl;
    }

    cout<<"Average waiting time is : ";
    cout<<wavg/(float)n<<endl;
    cout<<"average turnaround time : ";
    cout<<tavg/(float)n<<endl;


}