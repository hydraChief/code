#include <bits/stdc++.h>

using namespace std;

struct process {
    int pid;
    int bt;
    int at;
};

void waiting_time(process pr[], int n, int wt[]) {
    int rt[n];

    for (int i = 0; i < n; i++) {
        rt[i] = pr[i].bt;
    }

    int complete = 0, mn = INT_MAX, t = 0, finish_time = 0, shortest = 0;
    bool flag = false;

    while (complete != n) {
        for (int i = 0; i < n; i++) {
            if (pr[i].at <= t) {
                if (rt[i] < mn && rt[i] > 0) {
                    shortest = i;
                    mn = rt[i];
                    flag = true;
                }
            }
        }

        if (flag == false) {
            t++;
            continue;
        }

        rt[shortest]--;
        mn = rt[shortest];
        if (mn <= 0) mn = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            flag = false;
            finish_time = t + 1;
            wt[shortest] = max(finish_time - pr[shortest].at - pr[shortest].bt, 0);
        }
        t++;
    }
}

void TurnAroundTime(process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

int main() {
    process pr[] = { { 1, 6, 2 }, { 2, 2, 5 }, { 3, 8, 1 }, { 4, 3, 0 }, { 5, 4, 4 } };
    int n = sizeof(pr) / sizeof(pr[0]);
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waiting_time(pr, n, wt);
    TurnAroundTime(pr, n, wt, tat);

    cout << " P\t\t"
        << "BT\t\t"
        << "WT\t\t"
        << "TAT\t\t AT\n";

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << pr[i].pid << "\t\t"
            << pr[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] <<"\t\t"<<pr[i].at<< endl;
    }

    cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;

    return 0;
}

