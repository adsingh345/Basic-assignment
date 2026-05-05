#include <vector>
#include <iostream>

using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart, rightPart;
    for (int i = left; i <= mid; i++) leftPart.push_back(arr[i]);
    for (int i = mid + 1; i <= right; i++) rightPart.push_back(arr[i]);

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            // Inversion found!
            // All elements from leftPart[i] to leftPart[last] are > rightPart[j]
            arr[k++] = rightPart[j++];
            inversions += (leftPart.size() - i);
        }
    }

    while (i < leftPart.size()) arr[k++] = leftPart[i++];
    while (j < rightPart.size()) arr[k++] = rightPart[j++];

    return inversions;
}

long long countInversions(vector<int>& arr, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += countInversions(arr, left, mid);
        count += countInversions(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}
