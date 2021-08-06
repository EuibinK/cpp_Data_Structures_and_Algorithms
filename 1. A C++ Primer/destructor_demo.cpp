#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Vect {
    public:
        Vect (int n);   // constructor, given size
        ~Vect();        // destructor
    private:
        int*    data;   // an array holding the vector
        int     size;   // number of array entries
};

Vect::Vect(int n) {     // constructor
    size = n;
    data = new int[n];  // allocate array
}

Vect::~Vect() {         // destructor
    delete [] data;     // free the allocated array
}

/* We are not strictly required by C++ to provide our own destructor.
   However, if our class allocates memory, we should write a destructor to free this memory.
   --> If not, memory leak!
*/

int main() {
    return 0;
}
