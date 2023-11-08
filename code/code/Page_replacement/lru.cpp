#include<bits/stdc++.h>
using namespace std;

int main(){
    int pg[]= {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
    int capacity=4;
    deque<int> q(capacity);
    int count=0;
    int pf=0;
    deque<int> :: iterator itr;
    q.clear();

    for(int i:pg){
         itr = find(q.begin(),q.end(),i); 
        if(itr==q.end()){
            pf++;
            if(q.size()<capacity){
                q.push_back(i);
            }else{
                q.erase(q.begin());
                q.push_back(i);
            }
        }
        else{
            q.erase(itr);
            q.push_back(i);
        }
    }

    cout<<pf<<endl;
}