```cpp
// Maximum Xor For Each Query, https://leetcode.com/problems/maximum-xor-for-each-query/
// Given an array of integers and an array of queries, find the maximum XOR for each query.

// Brute force approach: O(n^2) complexity, where n is the number of queries
// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<int> result;
//         for (auto& query : queries) {
//             int max_xor = 0;
//             for (int num : nums) {
//                 max_xor = max(max_xor, num ^ query[0]);
//             }
//             result.push_back(max_xor);
//         }
//         return result;
//     }
// };

// Optimal solution: O(n log n) complexity, where n is the number of queries
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> result(queries.size());
        int j = 0;
        for (int i = 0; i < queries.size(); i++) {
            while (j < nums.size() && (nums[j] ^ queries[i][0]) <= queries[i][1]) {
                j++;
            }
            if (j > 0) {
                result[i] = nums[j - 1] ^ queries[i][0];
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {0, 1, 2, 3, 4};
    vector<vector<int>> queries1 = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> result1 = solution.maximizeXor(nums1, queries1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> queries2 = {{12, 4}, {8, 1}, {6, 3}};
    vector<int> result2 = solution.maximizeXor(nums2, queries2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```