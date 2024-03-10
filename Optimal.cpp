#include <bits/stdc++.h>

using namespace std;

int main() {
    //7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
    vector<int> re_string;
    int page_fault;

    cout << "Reference string: ";
    int num;
    while (cin >> num) {
        re_string.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }

    cout << "Enter No Of Frames: ";
    cin >> page_fault;

    int n = re_string.size();
    vector<int> m(page_fault, -1);
    vector<int> c;
    vector<int> l;
    int sum = 0;

    cout << "\nOutput will be: " << endl;

    for (int i = 0; i < n; i++) {
        int test = 0;
        for (int p = 0; p < page_fault; p++) {
            c.push_back(m[p]);
        }

        if (i < page_fault) {
            m[i] = re_string[i];
            sum += 1;
            re_string[i] = -99;
        } else {
            for (int j = 0; j < page_fault; j++) {
                if (re_string[i] == m[j]) {
                    test = 1;
                    re_string[i] = -99;
                    break;
                }
            }

            if (test == 0) {
                for (int s = 0; s < page_fault; s++) {
                    if (find(re_string.begin(), re_string.end(), m[s]) != re_string.end()) {
                        l.push_back(distance(re_string.begin(), find(re_string.begin(), re_string.end(), m[s])));
                    } else {
                        l.push_back(999);
                    }
                }
                int idx = max_element(l.begin(), l.end()) - l.begin();
                m[idx] = re_string[i];
                sum += 1;
                re_string[i] = -99;
            }
        }

        if (c == m) {
            for (int q = 0; q < page_fault; q++) {
                cout << "- ";
            }
        } else {
            for (int q = 0; q < page_fault; q++) {
                if (m[q] == -1) {
                    cout << "- ";
                } else {
                    cout << m[q] << " ";
                }
            }
        }
        c.clear();
        l.clear();
        cout << endl;
    }

    cout << "Page Fault: " << sum << endl;

    return 0;
}
