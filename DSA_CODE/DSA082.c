#include <iostream>
#include <vector>

using namespace std;

// First element >= x
int findLowerBound(const vector<int>& nums, int x) {
    int left = 0, right = nums.size() - 1;
    int ans = nums.size(); // Default if no element is >= x
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= x) {
            ans = mid;      // Possible answer, but look further left
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// First element > x
int findUpperBound(const vector<int>& nums, int x) {
    int left = 0, right = nums.size() - 1;
    int ans = nums.size(); // Default if no element is > x
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > x) {
            ans = mid;      // Possible answer, but look further left
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    if (!(cin >> n)) return 0;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cin >> x;

    cout << findLowerBound(nums, x) << " " << findUpperBound(nums, x) << endl;

    return 0;
}
