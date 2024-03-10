#include <bits/stdc++.h>

using namespace std;

int main() {
    //7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
    vector<int> re_string;
    int n;

    cout << "Reference string: ";
    int input;
    while (cin >> input) {
        re_string.push_back(input);
        if (cin.get() == '\n') {
            break;
        }
    }

    cout << "Total number of page frames: ";
    cin >> n;

    vector<string> memory(n, "*");

    int i = 0;
    int page_fault = 0;

    while (!re_string.empty()) {
        if (i == n) {
            i = 0;
        }
        int x = re_string.front();
        re_string.erase(re_string.begin());
        bool found = false;
        for (const string& str : memory) {
            if (str == to_string(x)) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "- - -" << endl;
        } else {
            page_fault++;
            memory[i] = to_string(x);
            i++;
            for (const string& str : memory) {
                cout << str << " ";
            }
            cout << endl;
        }
    }

    cout << "Page Fault: " << page_fault << endl;

    return 0;
}
