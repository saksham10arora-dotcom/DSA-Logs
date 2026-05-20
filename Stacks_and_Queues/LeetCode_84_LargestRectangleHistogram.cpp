/**
 * Problem: Largest Rectangle in Histogram (LeetCode 84)
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Monotonic Stack) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxA = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Max Area: " << largestRectangleArea(heights) << endl;
    return 0;
}






















