/**
 * Problem: Container With Most Water (LeetCode 11)
 * Link: https://leetcode.com/problems/container-with-most-water/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Brute Force ---
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int maxAreaBrute(vector<int>& height) {
    int maxW = 0;
    for (int i = 0; i < height.size(); i++) {
        for (int j = i + 1; j < height.size(); j++) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxW = max(maxW, h * w);
        }
    }
    return maxW;
}

// --- Optimal Solution (Two Pointers) ---
// Time Complexity: O(N)
// Space Complexity: O(1)
int maxAreaOptimal(vector<int>& height) {
    int maxW = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxW = max(maxW, h * w);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return maxW;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area: " << maxAreaOptimal(height) << endl;
    return 0;
}



































