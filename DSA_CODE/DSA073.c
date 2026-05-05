#include <iostream>
#include <string>
#include <vector>

using namespace std;

char firstNonRepeating(string s) {
    // Frequency array for 26 lowercase English letters
    vector<int> count(26, 0);

    // Step 1: Count occurrences
    for (char c : s) {
        count[c - 'a']++;
    }

    // Step 2: Find the first character with frequency 1
    for (char c : s) {
        if (count[c - 'a'] == 1) {
            return c;
        }
    }

    return '$';
}

int main() {
    string s;
    if (!(cin >> s)) return 0;
    
    cout << firstNonRepeating(s) << endl;
    
    return 0;
}
