#include<bits/stdc++.h>
using namespace std;

struct Process{
    int at,bt,pid;
};

int main(){
    vector<Process> p= {{7, 10,1}, {2,0, 2}, {2, 1,3}, {6, 3,4}};

    sort(p.begin(),p.end(),[](const Process &a,const Process &b){return a.at<b.at;});
    int n=p.size();
    vector<int> ct(n),wt(n),tot(n); 
    ct[0]=p[0].bt;
    for(int i=1;i<n;i++){
        ct[i]=max(ct[i-1],p[i].at)+p[i].bt;
    }

    for(int i=0;i<n;i++){
        tot[i]=ct[i]-p[i].at;
        wt[i]=tot[i]-p[i].bt;
    }

    float av_wt=0,av_tot=0;

    for(int i=0;i<n;i++){
        av_wt+=wt[i];
        av_tot+=tot[i];
    }
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout <<p[i].pid<< "\t\t\t\t" << p[i].at << "\t\t\t\t" << p[i].bt << "\t\t\t\t"
             << ct[i] << "\t\t\t\t" << wt[i] << "\t\t\t\t" << tot[i] << endl;
    }
    cout << "Average Waiting Time: " << av_wt/n << endl;
    cout << "Average Turnaround Time: " << av_tot/n << endl;
}