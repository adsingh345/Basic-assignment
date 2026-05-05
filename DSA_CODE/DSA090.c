#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool canPaint(const vector<int>& boards, int k, long long maxTime) {
    int paintersNeeded = 1;
    long long currentTime = 0;

    for (int length : boards) {
        if (currentTime + length > maxTime) {
            paintersNeeded++;
            currentTime = length;
            if (paintersNeeded > k) return false;
        } else {
            currentTime += length;
        }
    }
    return true;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> boards(n);
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> boards[i];
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
