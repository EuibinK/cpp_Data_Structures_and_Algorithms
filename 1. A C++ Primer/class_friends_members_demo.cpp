#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// friend function demo
class SomeClass {
    private:
        int secret;
    public:
        // ...
        SomeClass(int n = 3);
        friend ostream& operator<<(ostream& out, const SomeClass& x);
            // gives << operator access to secret
            // friend?? -- this function may access the class's private data
};

SomeClass::SomeClass(int n) {
    secret = n;
}

ostream& operator<<(ostream& out, const SomeClass& x) {
    out << x.secret;

    return out;
}

// friend member demo
class Vector {                                  // a 3-element vector
    public: // ...
    private:
        double coord[3];                        // storage for coordinates
        friend class Matrix;                    // give Matrix access to coord
            // Matrix can access all the private members of class Vector
};

class Matrix {                                   // a 3x3 matrix
    public:
        Vector multiply(const Vector& v);       // multiply by vector v
        // ... other public members omitted
    private:    
        double a[3][3];                         // matrix entries
};

Vector Matrix::multiply(const Vector& v) {      // multiply by vector v
    Vector w;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            w.coord[i] += a[i][j] * v.coord[j];  // access to coord allowed
        }
    }
    return w;
}


int main() {
    
    SomeClass a(5);
    cout << a << endl;

    return 0;
}


/* Note that "friendship" is not transitive
 *  E.g. if a new class Tensor is a friend of Matrix, Tensor would not be a friend of Vector, unless it is explicitly declared
 */
