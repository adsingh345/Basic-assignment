#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        std::vector<std::pair<int, double>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        // Sort by position descending
        std::sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double slowest_time = 0;

        for (int i = 0; i < n; i++) {
            // If current car takes longer than the slowest car in the fleet ahead
            if (cars[i].second > slowest_time) {
                fleets++;
                slowest_time = cars[i].second; // This car is the new lead bottleneck
            }
        }

        return fleets;
    }
};









