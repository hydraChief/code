#include<bits/stdc++.h>
using namespace std;

int main(){
    int p=3;
    int q=7;

    int n = p*q;
    int e=2;
    int phi=(p-1)*(q-1);

    while(e<phi){
        if(__gcd(e,phi)==1) break;
        e++;
    }

    int k=2;

    int d=(1+(k*phi))/e;
    int msg=12;
    cout<<"Message : "<<msg<<endl;
    int c= pow(msg,e);
    c=fmod(c,n);
    cout<<"Encryted msg :"<<c<<endl;

    int m=pow(c,d);
    m=fmod(m,n);
    cout<<"Decryted msg :"<<m<<endl;
}