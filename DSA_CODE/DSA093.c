#include <vector>
#include <iostream>

using namespace std;

class Sort {
public:
    /**
     * Binary search to find the correct position for 'key'.
     * To maintain stability, we find the rightmost possible position.
     */
    int binarySearch(const vector<int>& arr, int key, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (key < arr[mid])
                high = mid - 1;
            else
                // If key >= arr[mid], we move right to stay stable
                low = mid + 1;
        }
        return low;
    }

    void binaryInsertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            // Find the location where key should be inserted
            int pos = binarySearch(arr, key, 0, j);

            // Move all elements after 'pos' one position to the right
            while (j >= pos) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[pos] = key;
        }
    }
};

// Example usage:
int main() {
    vector<int> data = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
    Sort sol;
    
    sol.binaryInsertionSort(data);

    for (int x : data) cout << x << " ";
    return 0;
}
