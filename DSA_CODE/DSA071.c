#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
    int m;
    vector<int> table;
    const int EMPTY = -1;

public:
    HashTable(int size) : m(size), table(size, EMPTY) {}

    void insert(int key) {
        int h_k = key % m;
        for (int i = 0; i < m; i++) {
            int index = (h_k + i * i) % m;
            if (table[index] == EMPTY) {
                table[index] = key;
                return;
            }
        }
    }

    string search(int key) {
        int h_k = key % m;
        for (int i = 0; i < m; i++) {
            int index = (h_k + i * i) % m;
            if (table[index] == key) return "FOUND";
            if (table[index] == EMPTY) break;
        }
        return "NOT FOUND";
    }
};

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;
    
    HashTable ht(m);
    while (n--) {
        string op;
        int key;
        cin >> op >> key;
        if (op == "INSERT") ht.insert(key);
        else if (op == "SEARCH") cout << ht.search(key) << endl;
    }
    return 0;
}


