```cpp
// LeetCode problem 307: Range Sum Query Mutable, https://leetcode.com/problems/range-sum-query-mutable/
// Given an integer array nums, find the sum of the elements in the range [i, j] inclusive.
// The update(i, val) operation updates the ith element of the array to a new value.

// Brute force approach: O(n) for sumRange, O(1) for update
class NumArray_BruteForce {
public:
    vector<int> nums;
    NumArray_BruteForce(vector<int>& nums) : nums(nums) {}
    void update(int i, int val) {
        nums[i] = val;
    }
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += nums[k];
        }
        return sum;
    }
};

// Optimal solution: O(log n) for sumRange and update
class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) : n(nums.size()), tree(4 * n) {
        buildTree(nums, 0, 0, n - 1);
    }
    void update(int i, int val) {
        updateTree(0, 0, n - 1, i, val);
    }
    int sumRange(int i, int j) {
        return queryTree(0, 0, n - 1, i, j);
    }
    void buildTree(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(nums, 2 * node + 1, start, mid);
            buildTree(nums, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    void updateTree(int node, int start, int end, int i, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (i <= mid) {
                updateTree(2 * node + 1, start, mid, i, val);
            } else {
                updateTree(2 * node + 2, mid + 1, end, i, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    int queryTree(int node, int start, int end, int i, int j) {
        if (i > end || j < start) {
            return 0;
        }
        if (i <= start && j >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return queryTree(2 * node + 1, start, mid, i, j) + queryTree(2 * node + 2, mid + 1, end, i, j);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;  // Output: 9
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;  // Output: 8

    nums = {1, 2, 3, 4, 5};
    numArray = NumArray(nums);
    cout << numArray.sumRange(1, 3) << endl;  // Output: 9
    numArray.update(2, 10);
    cout << numArray.sumRange(1, 3) << endl;  // Output: 16

    nums = {1, 3, 5, 7, 9, 11};
    numArray = NumArray(nums);
    cout << numArray.sumRange(0, 5) << endl;  // Output: 36
    numArray.update(3, 15);
    cout << numArray.sumRange(0, 5) << endl;  // Output: 44

    return 0;
}
```