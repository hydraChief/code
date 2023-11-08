#include<bits/stdc++.h>
using namespace std;

bool check(int fr[],int k){
    for(int i=0;i<4;i++){
        if(fr[i]==k) return 1;
    }

    return 0;
}

int findin(int fr[],int pg[],int st,int n){
    int res=-1,max=-1;

    for(int i=0;i<4;i++){
        int j=st;
        for( j=st;j<n;j++){
            if(pg[j]=fr[i]){
                if(max<j){
                    res=i;
                    max=j;
                }
                break;
            }
        }
        if(j==n) return i;
    }

    return (res==-1) ?0:res;
}



int main(){
    int pg[]= {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int m=sizeof(pg)/sizeof(pg[0]);
    int n=4;
    int fr[n];
    int hit=0,miss=0,t=0;

    for(int i:pg){
        if(check(fr,i)){
            hit++;
            continue;
        }
        miss++;
        if(t<n){
            fr[t++]=i;
            continue;
        }
        int j=findin(fr,pg,i+1,m);
        fr[j]=i;
    }

    cout<<"Hit : "<<hit<<endl<<"Miss : "<<miss<<endl;
}