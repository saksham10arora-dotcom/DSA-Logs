```cpp
// Escape The Ghosts, https://leetcode.com/problems/escape-the-ghosts/, 
// You are playing a game with ghosts. Given a 2D array of ghosts where ghosts[i] = [xi, yi] 
// represents the position of the ith ghost. Your goal is to escape all the ghosts and reach the 
// target position, target = [tar_x, tar_y] in the array. Each step, it is possible to move either 
// one step to the right or one step to the left, as well as one step to the up or one step to the down. 
// If there is no possible way to reach the target position, return false.

#include <iostream>
#include <vector>
#include <cmath>

// Brute force approach with O(n) complexity
bool escapeGhostsBruteForce(std::vector<std::vector<int>>& ghosts, std::vector<int>& target) {
    int player_x = 0, player_y = 0;
    int tar_x = target[0], tar_y = target[1];
    int player_distance = std::abs(tar_x - player_x) + std::abs(tar_y - player_y);
    for (auto& ghost : ghosts) {
        int ghost_distance = std::abs(tar_x - ghost[0]) + std::abs(tar_y - ghost[1]);
        if (ghost_distance <= player_distance) {
            return false;
        }
    }
    return true;
}

// Optimal solution with O(n) complexity
bool escapeGhostsOptimal(std::vector<std::vector<int>>& ghosts, std::vector<int>& target) {
    int tar_x = target[0], tar_y = target[1];
    int player_distance = std::abs(tar_x) + std::abs(tar_y);
    for (auto& ghost : ghosts) {
        int ghost_distance = std::abs(tar_x - ghost[0]) + std::abs(tar_y - ghost[1]);
        if (ghost_distance <= player_distance) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> ghosts1 = {{1, 0}, {0, 3}};
    std::vector<int> target1 = {0, 1};
    std::cout << std::boolalpha << escapeGhostsOptimal(ghosts1, target1) << std::endl; // True

    std::vector<std::vector<int>> ghosts2 = {{1, 0}};
    std::vector<int> target2 = {2, 0};
    std::cout << std::boolalpha << escapeGhostsOptimal(ghosts2, target2) << std::endl; // False

    std::vector<std::vector<int>> ghosts3 = {{2, 0}};
    std::vector<int> target3 = {1, 0};
    std::cout << std::boolalpha << escapeGhostsOptimal(ghosts3, target3) << std::endl; // False

    return 0;
}
```