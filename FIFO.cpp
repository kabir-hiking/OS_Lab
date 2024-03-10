#include <bits/stdc++.h>

using namespace std;

int main() {
    int capacity;
    cout << "Enter the memory capacity: ";
    cin >> capacity;

    list<int> pages;
    int page, pagefault = 0;
    cout << "Enter the page reference string (space-separated, -1 to end): \n";

    while (cin >> page) {
        if (page == -1) break;

        if (pages.size() < static_cast<size_t>(capacity)) {
            if (find(pages.begin(), pages.end(), page) == pages.end()) {
                pages.push_back(page);
                pagefault++;
            }
        } else {
            if (find(pages.begin(), pages.end(), page) == pages.end()) {
                int oldest = pages.front();
                pages.pop_front();
                pages.push_back(page);
                pagefault++;
                cout << "Page " << oldest << " is replaced by page " << page << endl;
            }
        }

        cout << "Current pages in memory: ";
        for (int p : pages) {
            cout << p << " ";
        }
        cout << endl;
    }

    cout << "Total page faults: " << pagesfault << endl;

    return 0;
}
