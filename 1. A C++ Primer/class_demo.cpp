#include <iostream>
#include <string>

using namespace std;

class Counter {
    public:
        Counter();
        int getCount();
        void increaseBy(int x);
    private:
        int count;
};

Counter::Counter() {
    count = 0;
}

int Counter::getCount() {
    return count;
}

void Counter::increaseBy(int x) {
    count += x;
}

int main() {
    
    Counter ctr;
    cout << ctr.getCount() << endl;
    
    ctr.increaseBy(3);
    cout << ctr.getCount() << endl;

    ctr.increaseBy(5);
    cout << ctr.getCount() << endl;

    return 0;
}
