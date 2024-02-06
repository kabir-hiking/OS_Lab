
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define clr(c, val) memset(c, val, sizeof(c))
#define inf 1e9
#define OO 1e+7


void calculateWaitingTime(const vector<pair<string, int>>& processes, vector<int>& waiting_time, int quantum) {
    vector<pair<string, int>> remaining_time(processes.begin(), processes.end());

    int n = processes.size();
    int time = 0;
    bool allDone = false;

    while (!allDone) {
        allDone = true;
        for (int i = 0; i < n; ++i) {
            if (remaining_time[i].second > 0) {
                allDone = false;
                if (remaining_time[i].second > quantum) {
                    time += quantum;
                    remaining_time[i].second -= quantum;
                } else {
                    time += remaining_time[i].second;
                    waiting_time[i] = time - processes[i].second;
                    remaining_time[i].second = 0;
                }
            }
        }
    }
}


float calculateAverageWaitingTime(const vector<int>& waiting_time) {
    int total_waiting_time = 0;
    for (int time : waiting_time) {
        total_waiting_time += time;
    }
    return (float)total_waiting_time / waiting_time.size();
}

int main() {
 
    int num_processes = 4;
    vector<pair<string, int>> processes;
    string processElement;
    int burstElemnt;
 
    cout << "Enter process IDs and burst times:\n";
    for (int i = 0; i < num_processes; i++) {
        cin >> processElement >> burstElemnt;
        processes.push_back({processElement,burstElemnt});
        
    }

  
    int quantum = 5;
    vector<int> waiting_time(num_processes, 0);
    calculateWaitingTime(processes, waiting_time, quantum);

    float average_waiting_time = calculateAverageWaitingTime(waiting_time);
    cout << "Average waiting time will be = " << average_waiting_time <<" ms"<< endl;

    return 0;
}




















// cin >> processes[i].first , processes[i].second;
        // cout << "Process " << i + 1 << " ID: ";
        // cin >> processes[i].first;
        // cout << "Burst time for process " << processes[i].first << ": ";
        // cin >> processes[i].second;