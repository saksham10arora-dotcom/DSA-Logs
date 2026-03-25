```cpp
// LeetCode problem 1380: Range Module Optimized
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// A Range Module is a module that tracks any overlapping activity of a set of intervals.
// In particular, two intervals [start1, end1] and [start2, end2] are considered to be overlapping if start1 <= end2 and start2 <= end1.

#include <iostream>
#include <set>

class RangeModule {
public:
    std::set<int> intervals;

    RangeModule() {}

    void addRange(int left, int right) {
        // O(n) complexity
        auto it = intervals.lower_bound(left);
        while (it != intervals.end() && *it <= right) {
            right = std::max(right, *it + 1);
            it = intervals.erase(it);
        }
        it = intervals.lower_bound(left);
        if (it != intervals.begin()) {
            --it;
            if (*it + 1 >= left) {
                left = *it;
                intervals.erase(it);
            }
        }
        intervals.insert(left);
        intervals.insert(right);
    }

    bool queryRange(int left, int right) {
        // O(log n) complexity
        auto it = intervals.lower_bound(left);
        if (it == intervals.end() || *it > right) return false;
        auto nextIt = intervals.upper_bound(right);
        --nextIt;
        return *nextIt >= right;
    }

    void removeRange(int left, int right) {
        // O(n) complexity
        auto it = intervals.lower_bound(left);
        while (it != intervals.end() && *it <= right) {
            it = intervals.erase(it);
        }
        auto it2 = intervals.lower_bound(left);
        if (it2 != intervals.begin()) {
            --it2;
            if (*it2 + 1 > left) {
                intervals.insert(left);
            }
        }
        it2 = intervals.upper_bound(right);
        if (it2 != intervals.end() && *it2 > right + 1) {
            intervals.insert(right + 1);
        }
    }
};

int main() {
    RangeModule rangeModule;
    rangeModule.addRange(10, 20);
    rangeModule.removeRange(14, 16);
    std::cout << std::boolalpha << rangeModule.queryRange(10, 14) << std::endl;  // true
    std::cout << std::boolalpha << rangeModule.queryRange(13, 15) << std::endl;  // false
    std::cout << std::boolalpha << rangeModule.queryRange(16, 17) << std::endl;  // true
    return 0;
}
```