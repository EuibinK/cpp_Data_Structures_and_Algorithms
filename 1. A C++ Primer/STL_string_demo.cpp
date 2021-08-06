#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "ABCDEFGCD";

    s.find("CD");       // Return the index of first occurrence of string "CD" in s
    s.find("CD", 3);    // Return the index of first occurrence of string "CD" in s on or after position 3
    s.substr(2, 3);     // Return the substring starting at position 2 of s and  consisting of 3 characters
    s.insert(2, "XXX"); // Insert string "XXX" just prior to index 2 in s
        // ABXXXCDEFGCD
    s.erase(2, 3);      // Remove the substring of length 3 starting at 2
        // ABCDEFGCD
    s.replace(7, 2, "HI"); // Replace the substring of length 2 starting at index i with "HI"
        // ABCDEFGHI
    
    getline(cin, s); // Read a single line from the input stream is and store the result in s



    // String can also be compared lexicographically using the C++ comparison operators (<, <=, >, >=, ==, and !=)

    return 0;
}
