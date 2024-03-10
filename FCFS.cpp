// Description: FCFS Disk Scheduling Algorithm is the simplest of all the Disk Scheduling Algorithms. In FCFS, the requests are addressed in the order they arrive in the disk queue.
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
    cout << "Enter Number of Address: ";
    int no_of_address;
    cin >> no_of_address;
 
    vector <int> address(no_of_address);
    cout << "Enter Address: \n";
    for (int i = 0; i < no_of_address; i++) {
        cin >> address[i]; 
    }  
 
    int head;
    cin >> head;

    cout << "Path: " << head << ' ';
    for (auto i : address) {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "Calculating Distance: \n";
    int total_dis = 0;
    for (int i = 0; i < no_of_address; i++) {
        cout << "abs(" << head << " - " << address[i] << ") ";
        if (i != no_of_address - 1) cout << "+ ";
        else cout << "= ";
        total_dis += abs(head - address[i]);
        head = address[i];
    }

    cout << total_dis << '\n';
 
    return 0;
}

// input
// 8
// 98 183 37 122 14 124 65 67
// 53