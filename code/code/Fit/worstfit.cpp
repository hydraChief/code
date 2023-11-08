#include<bits/stdc++.h> 
using namespace std; 
void firstFit(int blockSize[], int m, 
			int processSize[], int n) 
{ 

	int allocation[n]; 
	memset(allocation, -1, sizeof(allocation)); 
 
	for (int i = 0; i < n; i++) 
	{ 
        int mx=0,res= -1;
		for (int j = 0; j < m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]  && blockSize[j]>mx) 
			{ 
				mx=blockSize[j];
                res=j;
			} 
		} 
        if(res !=-1)
       { allocation[i]=res;
        blockSize[res]-=processSize[i];}
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t"
			<< processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

int main() 
{ 
	int blockSize[] = {100, 500, 200, 300, 600}; 
	int processSize[] = {212, 417, 112, 426}; 
	int m = sizeof(blockSize) / sizeof(blockSize[0]); 
	int n = sizeof(processSize) / sizeof(processSize[0]); 

	firstFit(blockSize, m, processSize, n); 

	return 0 ; 
} 
