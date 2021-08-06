#include <vector>
#include "CreditCard.h"

using namespace std;

void testCard() {
    vector<CreditCard*> wallet(10);

    wallet[0] = new CreditCard("5391 0375 9387 5309", "EK", 2500);
    wallet[1] = new CreditCard("1234 5678 9876 5432", "EK", 3500);
    wallet[2] = new CreditCard("0000 0000 0000 0000", "EK", 5000);

    for (int i = 1; i <= 16; i++) {
        wallet[0]->chargeIt(double(i));
        wallet[1]->chargeIt(2*i);
        wallet[2]->chargeIt(double(3*i));
    }

    cout << "Card payments:\n";
    for (int i = 0; i < 3; i++) {
        cout << *wallet[i];
        while (wallet[i]->getBalance() > 100.0) {
            wallet[i]->makePayment(100.0);
            cout << "New balance = " << wallet[i]->getBalance() << endl;
        }

        cout << endl;
        delete wallet[i];
    }
}

int main() {
    testCard();
    return EXIT_SUCCESS;
}
