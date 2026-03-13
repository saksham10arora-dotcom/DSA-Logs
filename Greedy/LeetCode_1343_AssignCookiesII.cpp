```cpp
// LeetCode problem 1343: Assign Cookies II
// https://leetcode.com/problems/assign-cookies-ii/
// Assign cookies to children such that the maximum number of children get their favorite cookie.

// Brute force approach: Try all possible assignments of cookies to children (O(2^n))
// This approach is inefficient and will not work for large inputs.

// Optimal solution: Sort both the cookies and the children's favorite cookies, then assign the smallest cookie to the child with the smallest favorite cookie (O(n log n))
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main() {
    Solution solution;
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << solution.findContentChildren(g1, s1) << endl;  // Output: 1

    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << solution.findContentChildren(g2, s2) << endl;  // Output: 2

    vector<int> g3 = {1, 2, 3};
    vector<int> s3 = {3, 4, 5};
    cout << solution.findContentChildren(g3, s3) << endl;  // Output: 3

    return 0;
}
```