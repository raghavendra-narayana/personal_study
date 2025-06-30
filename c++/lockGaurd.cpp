// C++ Program using std::lock_guard
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

// Global mutex to protect shared_data
mutex mtx;

// Shared data variable
int shared_data = 0;

// Function to increment shared_data
void increment_data() {
    // Create a lock_guard object which locks the mutex
    lock_guard<mutex> lock(mtx);
    
    // Critical section: safely modify shared_data
    shared_data+=2;
    
    // Lock is automatically released when 'lock' goes out of scope
}

int main() {
    // Create two threads that run the increment_data function
    thread t1(increment_data);
    thread t2(increment_data);
    
    // Wait for both threads to finish
    t1.join();
    t2.join();
    
    // Output the value of shared_data
    cout << "Value of shared variable: " << shared_data;
    
    return 0;
}