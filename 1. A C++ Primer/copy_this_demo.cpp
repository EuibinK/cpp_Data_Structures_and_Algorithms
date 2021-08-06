#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Vect {
    public:
        Vect(int n = 10);
        Vect(const Vect& a); // copy constructor
        ~Vect();
        Vect& operator=(const Vect& a);
    private:
        int*    data;
        int     size;
};

Vect::Vect(int n) {
    size = n;
    data = new int[n];
}

Vect::~Vect() {
    delete [] data;
}

Vect::Vect(const Vect& a) {             // copy constructor from a
    size = a.size;                      // copy sizes
    data = new int[size];               // allocate new array
    for (int i = 0; i < size; i++) {    // copy the vector contents
        data[i] = a.data[i];
    }
}

Vect& Vect::operator=(const Vect& a) {      // assignment operator from a
    if (this != &a) {                       // avoid self-assignment
        // this -- address of this instance
        delete [] data;                     // delete old array
        size = a.size;                      // set new size
        data = new int[size];               // allocate new array
        for (int i = 0; i < size; i++) {    // copy the vector contents
            data[i] = a.data[i];
        }
    }
    return *this; // enables chained assignments
                    // a = b = c;
                    // --> b = c invokes the assignment opeartor, copying variable c to b and then returns a reference to b
                    // --> this result is then assigned to variable a
}

int main() {
    // Suppose we don't define copy constructor and assgnment operator
    Vect a(100);            // a is a vector of size 100
    Vect b = a;             // initialize b from a (DANGER!)
    Vect c;                 // c is a vector (default size: 10)
    c = a;                  // assign a to c (DANGER! --> memory leak)
                                // lost the pointer to c's original 10-element array

    /* without copy constructor, the system uses its default, which simply copies each member of a to b
       b.data = a.data --> does not copy the contents of the array
        --> copies the pointer to the array's initial element (shallow copy)

    --> Hence, if a class allocates memory, we need to provide a copy constructor and assignment operator to allocate new memory for making copies
    */


    return 0;
}


/* -- Summary --
 * Every class that allocates its own objects using new should:
 *
 *      1. Define a destructor to free any allocated objects
 *      2. Define a copy constructor, which allocates its own new member stoarge and copies the contents of member variables
 *      3. Define an assignment operator, which deallocates old storage, allocates new storage, and copies all member variables
 *
 */
