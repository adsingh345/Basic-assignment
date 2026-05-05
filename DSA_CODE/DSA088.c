#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if we can place k cows with at least 'dist' distance
bool canPlaceCows(const vector<int>& stalls, int k, int dist) {
    int count = 1; // Place first cow in the first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count >= k) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Binary search requires sorted positions
    sort(stalls.begin(), stalls.end());

    int left = 1; // Minimum possible distance
    int right = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            ans = mid;        // This distance works, try for a larger one
            left = mid + 1;
        } else {
            right = mid - 1;  // Too large, reduce the distance
        }
    }

    cout << ans << endl;

    return 0;
}
