#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& pages, int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book is larger than our limit, it's impossible
        if (pages[i] > maxPages) return false;

        if (currentPages + pages[i] > maxPages) {
            studentsRequired++;
            currentPages = pages[i];
            if (studentsRequired > m) return false;
        } else {
            currentPages += pages[i];
        }
    }
    return true;
}

int allocateBooks(vector<int>& pages, int n, int m) {
    if (m > n) return -1; // More students than books

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(pages, n, m, mid)) {
            result = mid;
            high = mid - 1; // Try to find an even smaller maximum
        } else {
            low = mid + 1; // Increase the limit
        }
    }
    return result;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << allocateBooks(pages, n, m) << endl;

    return 0;
}









































