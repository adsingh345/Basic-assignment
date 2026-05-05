#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class QuickSort {
public:
    // Entry point for sorting
    void sort(vector<int>& nums, string scheme = "Lomuto") {
        if (scheme == "Hoare") {
            quickSortHoare(nums, 0, nums.size() - 1);
        } else {
            quickSortLomuto(nums, 0, nums.size() - 1);
        }
    }

private:
    // --- LOMUTO SCHEME ---
    void quickSortLomuto(vector<int>& arr, int low, int high) {
        if (low < high) {
            int p = partitionLomuto(arr, low, high);
            quickSortLomuto(arr, low, p - 1); // p is in final place
            quickSortLomuto(arr, p + 1, high);
        }
    }

    int partitionLomuto(vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // Rightmost element as pivot
        int i = low;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    // --- HOARE SCHEME ---
    void quickSortHoare(vector<int>& arr, int low, int high) {
        if (low < high) {
            int p = partitionHoare(arr, low, high);
            // p is NOT necessarily in final place, just a split point
            quickSortHoare(arr, low, p); 
            quickSortHoare(arr, p + 1, high);
        }
    }

    int partitionHoare(vector<int>& arr, int low, int high) {
        int pivot = arr[low + (high - low) / 2]; // Middle element as pivot
        int i = low - 1;
        int j = high + 1;
        while (true) {
            do { i++; } while (arr[i] < pivot);
            do { j--; } while (arr[j] > pivot);
            if (i >= j) return j;
            swap(arr[i], arr[j]);
        }
    }
};

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> data = {3, 2, 1, 5, 6, 4};
    QuickSort qs;

    cout << "Original: ";
    printArray(data);

    qs.sort(data, "Lomuto");
    cout << "Sorted (Lomuto): ";
    printArray(data);

    vector<int> data2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    qs.sort(data2, "Hoare");
    cout << "Sorted (Hoare): ";
    printArray(data2);

    return 0;
}
