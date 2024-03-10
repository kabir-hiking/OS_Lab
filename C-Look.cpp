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

    vector <int> path;
    path.push_back(head);
    vector <int> tmp;
    for (int i = 0; i < no_of_address; i++) {
        if (address[i] > head) {
            tmp.push_back(address[i]);
        }
    }

    sort(tmp.begin(), tmp.end());
    for (auto i : tmp) {
    	path.push_back(i);
    }

    tmp.clear();
    for (int i = 0; i < no_of_address; i++) {
        if (address[i] <= head) {
            tmp.push_back(address[i]);
        }
    }

    sort(tmp.begin(), tmp.end());
    for (auto i : tmp) {
    	path.push_back(i);
    }

    cout << "Path: ";
    for (auto i : path) {
        cout << i << ' ';
    }
    cout << '\n';

    cout << "Calculating Distance: \n";
    int total_dis = 0;
    for (int i = 1; i < path.size(); i++) {
        cout << "abs(" << path[i - 1] << " - " << path[i] << ") ";
        if (i != path.size() - 1) cout << "+ ";
        else cout << "= ";
        total_dis += abs(path[i - 1] - path[i]);
    }

    cout << total_dis << '\n';
 
    return 0;
}