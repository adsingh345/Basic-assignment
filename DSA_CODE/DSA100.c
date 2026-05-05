#include <vector>
#include <algorithm>
#include <set>

class Solution {
    std::vector<int> bit;
    void update(int idx, int val, int n) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);
        
        // Coordinate Compression
        std::set<int> sorted_set(nums.begin(), nums.end());
        std::vector<int> ranks(sorted_set.begin(), sorted_set.end());
        
        bit.assign(ranks.size() + 1, 0);
        
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Find rank of nums[i]
            int rank = std::lower_bound(ranks.begin(), ranks.end(), nums[i]) - ranks.begin() + 1;
            
            // Count elements already in BIT with rank < current rank
            result[i] = query(rank - 1);
            
            // Add current element to BIT
            update(rank, 1, ranks.size());
        }
        
        return result;
    }
};








