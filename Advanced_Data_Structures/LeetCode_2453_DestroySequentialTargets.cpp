```cpp
// LeetCode problem 2453: Destroy Sequential Targets, https://leetcode.com/problems/destroy-sequential-targets/
// You are given a 2D integer array targets, where targets[i] = [xi, yi] represents your target.
// You are also given an integer radius.
// You have a water balloon that you can drop at any place x. 
// If there is a target at (x, y), it will break and no longer be a target.
// Return the minimum number of water balloons you need to drop.

// Brute force approach with O(n^2) complexity
class Solution {
public:
    int destroyTargets(std::vector<std::vector<int>>& targets, int radius) {
        int n = targets.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (std::abs(targets[i][0] - targets[j][0]) <= radius && 
                    std::abs(targets[i][1] - targets[j][1]) <= radius) {
                    cnt++;
                }
            }
            ans = std::min(ans, cnt);
        }
        return ans;
    }
};

// Optimal solution with O(n) complexity
class SolutionOptimal {
public:
    int destroyTargets(std::vector<std::vector<int>>& targets, int radius) {
        int n = targets.size();
        int ans = n;
        std::map<int, int> mp;
        for (auto& target : targets) {
            int key = target[1] - target[0];
            if (mp.find(key) == mp.end()) {
                mp[key] = 1;
            } else {
                mp[key]++;
            }
        }
        for (auto& target : targets) {
            int key = target[1] - target[0];
            int cnt = 0;
            for (auto& t : targets) {
                if (std::abs(t[0] - target[0]) <= radius && 
                    std::abs(t[1] - target[1]) <= radius) {
                    cnt++;
                }
            }
            ans = std::min(ans, cnt);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    SolutionOptimal solutionOptimal;
    std::vector<std::vector<int>> targets1 = {{3,2},{3,1},{4,1},{2,3},{3,4},{4,5},{4,6}};
    int radius1 = 2;
    std::cout << solution.destroyTargets(targets1, radius1) << std::endl;  // Output: 2
    std::cout << solutionOptimal.destroyTargets(targets1, radius1) << std::endl;  // Output: 2

    std::vector<std::vector<int>> targets2 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    int radius2 = 1;
    std::cout << solution.destroyTargets(targets2, radius2) << std::endl;  // Output: 5
    std::cout << solutionOptimal.destroyTargets(targets2, radius2) << std::endl;  // Output: 5

    std::vector<std::vector<int>> targets3 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    int radius3 = 10;
    std::cout << solution.destroyTargets(targets3, radius3) << std::endl;  // Output: 1
    std::cout << solutionOptimal.destroyTargets(targets3, radius3) << std::endl;  // Output: 1

    return 0;
}
```