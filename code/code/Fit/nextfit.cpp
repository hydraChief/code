#include<bits/stdc++.h>
using namespace std;

void NextFit(int b[],int m, int p[],int n){
    int al[n],j=0,t=m-1;
     memset(al, -1, sizeof(al));
    for(int i=0;i<n;i++){
        while(j<m){
            if(b[j]>=p[i]){
                al[i]=j;
                b[j]-=p[i];
                t=(j-1)%m;
                break;
            }
            if(j==t){
                t=(j-1)%m;
                break;
            }
            j=(j+1)%m;
        }
    }  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t\t\t" << p[i]
            << "\t\t\t\t";
        if (al[i] != -1)
            cout << al[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}


    int main()
{
    int blockSize[] = { 5, 10, 20 };
    int processSize[] = { 10, 20, 5 };
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
 
    NextFit(blockSize, m, processSize, n);
 
    return 0;
}
