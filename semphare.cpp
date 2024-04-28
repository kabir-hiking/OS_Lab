#include <bits/stdc++.h>
#include <thread>
#include <mutex>

mutex mutex;

void printHello(int numPrints) {
    lock_guard<mutex> lock(mutex);
    for (int i = 0; i < numPrints; i++) {
        cout << "Hello from (pid = " << this_thread::get_id() << ")\n";
    }
}

int main() {
    int numPrints = 20; // Change the number of prints here
    thread thread1(printHello, numPrints);
    thread thread2(printHello, numPrints);
    
    thread1.join();
    thread2.join();

    return 0;
}
