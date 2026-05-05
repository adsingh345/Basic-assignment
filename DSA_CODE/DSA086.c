#include <iostream>

class Solution {
public:
    long long integerSqrt(long long n) {
        if (n < 2) return n;

        long long left = 0, right = n;
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            // Check mid * mid <= n without overflow
            if (mid <= n / mid) {
                ans = mid;      // mid is a candidate
                left = mid + 1; // Try for a larger integer
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    long long n;
    if (!(std::cin >> n)) return 0;
    
    Solution sol;
    std::cout << sol.integerSqrt(n) << std::endl;
    
    return 0;
}
