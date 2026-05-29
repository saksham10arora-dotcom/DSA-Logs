```cpp
// LeetCode problem 458: Poor Pigs, https://leetcode.com/problems/poor-pigs/
// There are buckets buckets of liquid, where exactly one bucket is poisonous. 
// We need to find out which bucket is poisonous within a certain time limit.

// Brute force approach: Try all possible combinations of buckets and time limits, O(2^(buckets * minutesToTest)) complexity
// This approach is not feasible due to its high time complexity.

// Optimal solution: Use a mathematical approach to calculate the minimum number of pigs required, O(log minutesToTest) complexity
class Solution {
public:
    int poorPigs(int buckets, int minutesToTest) {
        double states = (minutesToTest / 60) + 1;
        return (int)ceil(log(buckets) / log(states));
    }
};

int main() {
    Solution solution;
    // Test case 1:
    int buckets1 = 1000;
    int minutesToTest1 = 15;
    int result1 = solution.poorPigs(buckets1, minutesToTest1);
    // Test case 2:
    int buckets2 = 4;
    int minutesToTest2 = 15;
    int result2 = solution.poorPigs(buckets2, minutesToTest2);
    // Test case 3:
    int buckets3 = 4;
    int minutesToTest3 = 30;
    int result3 = solution.poorPigs(buckets3, minutesToTest3);
    return 0;
}
```