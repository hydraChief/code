#include <bits/stdc++.h>
using namespace std;


void roundRobin(int n, int tq, vector<int> ar, vector<int> bt){
	int timer = 0;
	int k = 1, completed = 0;

	vector<int> bt1(n), done(n);
	queue<int> q;
	
	for(int i=0; i<n; i++){
		bt1[i] = bt[i];
	}

	q.push(0);
	timer = ar[0];

	while(completed < n){
		int task = q.front();

		timer += min(bt1[task], tq);
		bt1[task] -= min(bt1[task], tq);

		for(int i = k; i < n; i++){
			if(ar[i] <= timer){
				q.push(i);
				k++;
			}
		}

		if(bt1[task] == 0){
			done[task] = timer;
			completed++;
			q.pop();
		}
		else{
			q.pop();
			q.push(task);
		}
	}

	
	vector<int> wt(n), tat(n);

	for(int i=0; i<n; i++){
		tat[i] = done[i] - ar[i];
		wt[i] = tat[i] - bt[i];
	}

	for(int i=0; i<n; i++){
		cout << wt[i] << " ";
	}
	cout << endl;
	for(int i=0; i<n; i++){
		cout << tat[i] << " ";
	}
}


int main(){
	int n, tq;
	cin>>n>>tq;

	vector<int> ar(n), bt(n);
	for(int i=0; i<n; i++) cin>>ar[i];
	for(int i=0; i<n; i++) cin>>bt[i];

	roundRobin(n, tq, ar, bt);
}