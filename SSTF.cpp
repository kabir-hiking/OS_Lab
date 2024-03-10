// Description: Shortest Seek Time First (SSTF) algorithm is a disk scheduling algorithm that selects the disk I/O request that is closest to the current head position.
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
    cout << "Enter Number of Address: ";
    int no_of_address;
    cin >> no_of_address;
 
    multiset <int> address;
    cout << "Enter Address: \n";
    for (int i = 0; i < no_of_address; i++) {
    	int x;
        cin >> x; 
        
        address.insert(x);
    }  
 
    int head;
    cin >> head;

    vector <int> path;
    path.push_back(head);
    for (int i = 0; i < no_of_address; i++) {
        int mn = INT_MAX, val;
        for (auto j : address) {
            if (abs(j - head) < mn) {
                val = j;
                mn = abs(j - head);
            }
        }
        head = val;
        address.erase(val);
        path.push_back(head);
    }

    cout << "Path: ";
    for (auto i : path) {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "Calculating Distance: \n";
    int total_dis = 0;
    for (int i = 1; i <= no_of_address; i++) {
        cout << "abs(" << path[i - 1] << " - " << path[i] << ") ";
        if (i != no_of_address) cout << "+ ";
        else cout << "= ";
        total_dis += abs(path[i - 1] - path[i]);
    }

    cout << total_dis << '\n';
 
    return 0;
}

// input
// 8
// 98 183 37 122 14 124 65 67
// 53