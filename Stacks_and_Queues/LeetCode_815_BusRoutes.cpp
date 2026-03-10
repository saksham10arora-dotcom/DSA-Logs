```cpp
// LeetCode problem 815: Bus Routes, https://leetcode.com/problems/bus-routes/
// We have a list of bus routes. Each route is a list of bus stops. 
// We need to find the least number of buses we must take to travel from our starting bus stop to our destination bus stop.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        std::unordered_map<int, std::vector<int>> stopToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }
        
        std::unordered_set<int> visitedBus;
        std::unordered_set<int> visitedStop;
        std::queue<std::pair<int, int>> queue;
        queue.push({source, 0});
        visitedStop.insert(source);
        
        while (!queue.empty()) {
            auto [stop, busCount] = queue.front();
            queue.pop();
            
            for (int bus : stopToBus[stop]) {
                if (visitedBus.find(bus)!= visitedBus.end()) continue;
                visitedBus.insert(bus);
                
                for (int nextStop : routes[bus]) {
                    if (nextStop == target) return busCount + 1;
                    if (visitedStop.find(nextStop)!= visitedStop.end()) continue;
                    visitedStop.insert(nextStop);
                    queue.push({nextStop, busCount + 1});
                }
            }
        }
        
        return -1;
    }
};

// Brute force approach: O(n^2 * m) where n is the number of bus routes and m is the maximum number of stops in a route
// Optimal solution: O(n * m) where n is the number of bus routes and m is the maximum number of stops in a route

int main() {
    Solution solution;
    
    std::vector<std::vector<int>> routes1 = {{1, 2, 7}, {3, 6, 7}};
    std::cout << solution.numBusesToDestination(routes1, 1, 6) << std::endl;  // Output: 2
    
    std::vector<std::vector<int>> routes2 = {{2}, {3}, {7}, {3, 6, 7}};
    std::cout << solution.numBusesToDestination(routes2, 1, 6) << std::endl;  // Output: -1
    
    std::vector<std::vector<int>> routes3 = {{1, 9, 12, 20, 23, 24, 35, 38}, {10, 17, 18, 26, 30, 34, 37, 40}, {16, 25, 27, 29, 33, 36, 39, 41}, {2, 5, 7, 8, 19, 20, 27, 28, 35, 44, 47}, {1, 2, 5, 9, 13, 14, 17, 20, 21, 27, 31, 32, 37, 40, 41, 45, 48}};
    std::cout << solution.numBusesToDestination(routes3, 37, 17) << std::endl;  // Output: 2
    
    return 0;
}
```