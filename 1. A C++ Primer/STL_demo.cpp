#include <iostream>

// To use STL (Standard Template Library)
#include <stack>            // Container with LIFO access
#include <queue>            // Container with FIFO access
                                // or priority_queue -- queue ordered by value
#include <deque>            // Double-ended queue
#include <vector>           // Resizeable array
#include <list>             // Doubly liked list
#include <set>              // Set
#include <map>              // Associative array (dictionary)

using namespace std;

int main() {

    vector<int> scores(100);                // 100 integer scores
    vector<char> buffer(500);               // buffer of 500 characters

    // vector<Passenger> passenList(20);    // list of 20 Passengers

    /* STL vectors are superior to standard C++ arrays
        individual elements can be indexed using the usual index operator ([])
        and can be accessed by the   at   member function
            --> at  performs range checking and generates an error exception if the index is out of bounds
    */

    int i = 350;                        
    cout << scores[i];                      // index (range unchecked)
    buffer.at(i) = buffer.at(2 * i);        // index (range checked)
        // --> generates an error exception since the index is out of bounds

    vector<int> newScores = scores;         // copy scores to newScores
    scores.resize(scores.size() + 10);      // add room for 10 more elements


    return 0;
}
