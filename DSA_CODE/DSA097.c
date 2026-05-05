#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    int minMeetingRooms(std::vector<int> &start, std::vector<int> &end) {
        int n = start.size();
        if (n == 0) return 0;

        // Combine and sort meetings by start time
        std::vector<std::pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i]});
        }
        std::sort(meetings.begin(), meetings.end());

        // Min-heap to store end times of meetings currently in rooms
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Add the first meeting
        minHeap.push(meetings[0].second);

        for (int i = 1; i < n; i++) {
            // If the earliest finishing meeting ends before/at current meeting starts
            if (meetings[i].first >= minHeap.top()) {
                minHeap.pop(); // Reuse this room
            }
            
            // Put current meeting in a room (either new or reused)
            minHeap.push(meetings[i].second);
        }

        return minHeap.size();
    }
};
