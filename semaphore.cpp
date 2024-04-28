#include <bits/stdc++.h>
#include <thread>
#include <mutex>

std::mutex mutex;

void printHello(int numPrints) {
    std::lock_guard<std::mutex> lock(mutex);
    for (int i = 0; i < numPrints; i++) {
        std::cout << "Hello from (pid = " << std::this_thread::get_id() << ")\n";
    }
}

int main() {
    int numPrints = 7; 
    std::thread thread1(printHello, numPrints);
    std::thread thread2(printHello, numPrints);
    
    thread1.join();
    thread2.join();

    return 0;
}
