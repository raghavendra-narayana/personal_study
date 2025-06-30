// C++ Program to illustrate the use of Condition Variables
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <queue>

using namespace std;

// mutex to block threads
mutex mtx;
condition_variable cv_producer;
condition_variable cv_consumer;
// function to avoid spurios wakeup
queue<int> bufferQ;
#define BUFFER_SIZE 8

// producer function working as sender
void producer()
{
    int i=10;
    do{
    // Simulate data production
    //this_thread::sleep_for(chrono::seconds(2));

    // lock release
    unique_lock<mutex> lock(mtx);
    
    //cout << "lock producer i=" << i << endl;

    // Wait if buffer is full
    cv_producer.wait(lock, [] { return (bufferQ.size() < BUFFER_SIZE); });

    // variable to avoid spurious wakeup
    bufferQ.push(i);

    // logging notification to console
    cout << "Data Produced! " << i << endl;

    // notify consumer when done
    cv_consumer.notify_one();
    
    }while(--i>=0);
}

// consumer that will consume what producer has produced
// working as reciever
void consumer()
{
    
    int i=10;
    do{
    // locking
    unique_lock<mutex> lock(mtx);

    //cout << "lock consumer   i=" << i << endl;

    // Wait if buffer is empty
    cv_consumer.wait(lock, [] { return !bufferQ.empty(); });

    int item = bufferQ.front(); // Get item from buffer
    bufferQ.pop(); // Remove item from buffer
    
    cout << "Data consumed! " << item << endl;

    // notify producer when done
    cv_producer.notify_one();

    }while(--i>=0);
}

// drive code
int main()
{
    thread consumer_thread(consumer);
    thread producer_thread(producer);

    consumer_thread.join();
    producer_thread.join();

        return 0;
}