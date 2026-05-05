#include <vector>
#include <algorithm> // for std::max_element

using namespace std;

class Solution {
public:
    vector<int> countingSort(vector<int>& arr) {
        if (arr.empty()) return {};

        // 1. Find the maximum element to determine the range
        int maxVal = *max_element(arr.begin(), arr.end());

        // 2. Build the frequency (count) array
        vector<int> count(maxVal + 1, 0);
        for (int x : arr) {
            count[x]++;
        }

        // 3. Compute prefix sums
        // This tells us the actual position of each element in the output array
        for (int i = 1; i <= maxVal; i++) {
            count[i] += count[i - 1];
        }

        // 4. Build the output array
        vector<int> output(arr.size());
        // Iterate backwards through the original array to maintain stability
        for (int i = arr.size() - 1; i >= 0; i--) {
            int val = arr[i];
            int position = count[val] - 1; // 0-indexed position
            output[position] = val;
            count[val]--; // Decrement to handle duplicate values
        }

        return output;
    }
};
