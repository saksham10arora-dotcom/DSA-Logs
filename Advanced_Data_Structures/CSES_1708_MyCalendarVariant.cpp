```cpp
// My Calendar Variant, https://cses.fi/problemset/task/1708, 
// Given a list of events, determine the number of events that take place on each day.

#include <iostream>
#include <vector>
#include <map>

// Brute force approach: O(n^2) complexity
int bruteForce(const std::vector<std::pair<int, int>>& events) {
    std::map<int, int> days;
    for (const auto& event : events) {
        for (int i = event.first; i <= event.second; ++i) {
            days[i]++;
        }
    }
    int maxEvents = 0;
    for (const auto& day : days) {
        maxEvents = std::max(maxEvents, day.second);
    }
    return maxEvents;
}

// Optimal solution: O(n log n) complexity
int optimalSolution(const std::vector<std::pair<int, int>>& events) {
    std::vector<std::pair<int, int>> points;
    for (const auto& event : events) {
        points.push_back({event.first, 1});
        points.push_back({event.second + 1, -1});
    }
    std::sort(points.begin(), points.end());
    int maxEvents = 0, currentEvents = 0;
    for (const auto& point : points) {
        currentEvents += point.second;
        maxEvents = std::max(maxEvents, currentEvents);
    }
    return maxEvents;
}

int main() {
    std::vector<std::pair<int, int>> events1 = {{1, 3}, {2, 4}, {5, 7}};
    std::vector<std::pair<int, int>> events2 = {{1, 10}, {2, 3}, {3, 4}, {4, 5}};
    std::vector<std::pair<int, int>> events3 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    std::cout << optimalSolution(events1) << std::endl;  // Output: 2
    std::cout << optimalSolution(events2) << std::endl;  // Output: 3
    std::cout << optimalSolution(events3) << std::endl;  // Output: 1

    return 0;
}
```