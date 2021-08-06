#include <iostream>
#include <string>

using namespace std;

enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

class Passenger {
    public:
        Passenger(); // default constructor
        Passenger(const string& nm, MealType mp = NO_PREF, const string& ffn = "NONE");
        Passenger(const Passenger& pass); // copy constructor

        bool isFrequentFlyer() const;
        void getInfo();

        void makeFrequentFlyer(const string& newFreqFlyerNo);
        
        //...
    private:
        string    name;
        MealType  mealPref;
        bool      isFreqFlyer;
        string    freqFlyerNo;
};

Passenger::Passenger() {
    name = "--NO NAME--";
    mealPref = NO_PREF;
    isFreqFlyer = false;
    freqFlyerNo = "NONE";
}

Passenger::Passenger(const string& nm, MealType mp, const string& ffn)
    : name(nm), mealPref(mp), isFreqFlyer(ffn != "NONE") {
        freqFlyerNo = ffn;
    }

Passenger::Passenger(const Passenger& pass) {
    name = pass.name;
    mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer;
    freqFlyerNo = pass.freqFlyerNo;
}


bool Passenger::isFrequentFlyer() const {
    return isFreqFlyer;
}

void Passenger::makeFrequentFlyer(const string& newFreqFlyerNo) {
    isFreqFlyer = true;
    freqFlyerNo = newFreqFlyerNo;
}

void Passenger::getInfo() {
    cout << "Name: " << name << endl;
    cout << "Meal preference: " << mealPref << endl;
    cout << "Frequent flyer?: ";
    if (isFreqFlyer) {
        cout << "Y" << endl;
        cout << "FFN: " << freqFlyerNo << endl;
    }
    else
        cout << "N" << endl;
}

int main() {

    Passenger p1("EK", VEGETARIAN, "504788597");

    p1.getInfo();

    return 0;
}
