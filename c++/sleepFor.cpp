// C++ Program to demonstrate
// Use of sleep_for
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    // Displaying a Statement
    cout << "1st Line" << endl;

    // Halting the execution for 10000ms (milliseconds) or
    // 10 seconds
    std::this_thread::sleep_for(10000ms);

    // Displaying the line after waiting for 10 seconds
    cout << "2nd Line" << endl;
    return 0;
}