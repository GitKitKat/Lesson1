#include <iostream>
#include <chrono>
#include <deque>
#include <vector>
#include <list>

using namespace std;

// Constants
const int NUM_ELEMENTS = 1000000;

// Functions declarations
void ProfileBackInsertVector(vector<int>& vec);
void ProfileBackInsertList(list<int>& list);
void ProfileBackInsertDeque(deque<int>& deque);

void ProfileFrontInsertVector(vector<int>& vec);
void ProfileFrontInsertList(list<int>& list);
void ProfileFrontInsertDeque(deque<int>& deque);

// Functions Definitions
int main()
{
    vector<int> myVector;
    ProfileBackInsertVector(myVector);
    //ProfileFrontInsertVector(myVector);
    // TODO: Profile RandomAccessVector

    list<int> myList;
    ProfileBackInsertList(myList);
    ProfileFrontInsertList(myList);

    deque<int> myQueue;
    ProfileBackInsertDeque(myQueue);
    ProfileFrontInsertDeque(myQueue);
    // TODO: ProfileRandomAccessDeque

    return 0;
}

// VECTORS
void ProfileBackInsertVector(vector<int>& vec) {
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.push_back(i);
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the back for std::vector: " << duration.count() << " ms\n";
}

void ProfileFrontInsertVector(vector<int>& vec) {
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    vector<int>::iterator vit = vec.begin(); 
    // Insert elements at the front
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        vec.insert(vit, i);
        vit = vec.begin();
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the front for std::vector: " << duration.count() << " ms\n";
}

// LISTS
void ProfileBackInsertList(list<int>& list) {
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        list.push_back(i);
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the back for std::list: " << duration.count() << " ms\n";
}

void ProfileFrontInsertList(list<int>& lis) {
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    list<int>::iterator it = lis.begin();
    // Insert elements at the front
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        lis.insert(it, i);
        it = lis.begin();
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the front for std::list: " << duration.count() << " ms\n";
}

// DEQUES
void ProfileBackInsertDeque(deque<int>& deque) {
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the back
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        deque.push_back(i);
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the back for std::deque: " << duration.count() << " ms\n";
}

void ProfileFrontInsertDeque(deque<int>& deque) {
    // Start time
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    // Insert elements at the front
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        deque.push_front(i);
    }

    // End time
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    // Duration
    chrono::duration<double> duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to insert at the front for std::deque: " << duration.count() << " ms\n";
}