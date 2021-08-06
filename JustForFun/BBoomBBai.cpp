#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    int n;
    cout << "How many people are BBoomBBai-ing? ";
    cin >> n;

    double paid[n];
    double total;

    for (int i = 1; i <= n; i++) {
        cout << "Person " << i << " paid: ";
        cin >> paid[i-1];
        total += paid[i-1];
    }

    cout << endl;

    double avg = total / n;
    double diff[n];

    for (int i = 0; i < n; i++) {
        diff[i] = paid[i] - avg;
    }

    for (int i = 0; i < n; i++) {
        if (diff[i] > 0) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (diff[j] + diff[i] <= 0) {
                    diff[j] += diff[i];
                    cout << "Person " << j+1 << " -> Person " << i+1 << " $" << diff[i] << endl;
                    diff[i] = 0;
                    break;
                } else if (diff[j] != 0) {
                    diff[i] += diff[j];
                    cout << "Person " << j+1 << " -> Person " << i+1 << " $" << -diff[j] << endl;
                    diff[j] = 0;
                }
            }
        }
    }
    cout << endl << "Each person pays $" << avg << endl;

    return 0;
}
