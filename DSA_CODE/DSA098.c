class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. Sort by start time: O(N log N)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Get the last interval we added to the result
            vector<int>& last = merged.back();

            // 2. Compare: If current start <= previous end, they overlap
            if (intervals[i][0] <= last[1]) {
                // Merge by extending the end time to the maximum of both
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap, start a new entry in the result
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
