```cpp
// LeetCode problem 2710: Non Overlapping Advanced, https://leetcode.com/problems/non-overlapping-advanced/
// Given an array of intervals, find the maximum number of non-overlapping intervals.

// Brute force approach: Generate all possible subsets of intervals and check for non-overlapping, O(2^n * n)
class Solution {
public:
    int findNonOverlapping(int intervals[][2], int intervalsSize) {
        int maxCount = 0;
        for (int mask = 0; mask < (1 << intervalsSize); mask++) {
            bool nonOverlapping = true;
            int count = 0;
            for (int i = 0; i < intervalsSize; i++) {
                if ((mask & (1 << i)) != 0) {
                    bool overlaps = false;
                    for (int j = 0; j < i; j++) {
                        if ((mask & (1 << j)) != 0 && intervals[i][0] < intervals[j][1] && intervals[j][0] < intervals[i][1]) {
                            overlaps = true;
                            break;
                        }
                    }
                    if (!overlaps) {
                        count++;
                    } else {
                        nonOverlapping = false;
                        break;
                    }
                }
            }
            if (nonOverlapping) {
                maxCount = std::max(maxCount, count);
            }
        }
        return maxCount;
    }
};

// Optimal solution: Sort intervals by end time and use greedy algorithm, O(n log n)
class SolutionOptimal {
public:
    int findNonOverlapping(int intervals[][2], int intervalsSize) {
        std::sort(intervals, intervals + intervalsSize, [](int a[], int b[]) {
            return a[1] < b[1];
        });
        int count = 0;
        int lastEnd = -1;
        for (int i = 0; i < intervalsSize; i++) {
            if (intervals[i][0] >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }
        return count;
    }
};

int main() {
    SolutionOptimal solution;
    int intervals1[][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int intervals2[][2] = {{1, 2}, {1, 2}, {1, 2}};
    int intervals3[][2] = {{1, 2}, {2, 3}};
    std::cout << solution.findNonOverlapping(intervals1, 4) << std::endl;  // Output: 2
    std::cout << solution.findNonOverlapping(intervals2, 3) << std::endl;  // Output: 1
    std::cout << solution.findNonOverlapping(intervals3, 2) << std::endl;  // Output: 2
    return 0;
}
```