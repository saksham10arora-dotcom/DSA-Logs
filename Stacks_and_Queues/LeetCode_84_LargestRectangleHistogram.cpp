```cpp
// Largest Rectangle in Histogram, https://leetcode.com/problems/largest-rectangle-in-histogram/, 
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
// return the area of the largest rectangle in the histogram.

// Brute force approach: O(n^2) complexity, for each bar, calculate the area of the rectangle with this bar as the smallest bar
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;
//         for (int i = 0; i < n; i++) {
//             int minHeight = heights[i];
//             for (int j = i; j < n; j++) {
//                 minHeight = min(minHeight, heights[j]);
//                 maxArea = max(maxArea, minHeight * (j - i + 1));
//             }
//         }
//         return maxArea;
//     }
// };

// Optimal solution: O(n) complexity, use a stack to store the indices of the bars
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!s.empty() && heights[s.top()] > h) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights1 = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(heights1) << endl;  // Output: 10

    vector<int> heights2 = {2,4};
    cout << solution.largestRectangleArea(heights2) << endl;  // Output: 4

    vector<int> heights3 = {1,1};
    cout << solution.largestRectangleArea(heights3) << endl;  // Output: 2

    return 0;
}
```