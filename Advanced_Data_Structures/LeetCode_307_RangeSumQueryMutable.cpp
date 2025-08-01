/**
 * Problem: Range Sum Query - Mutable (LeetCode 307)
 * Link: https://leetcode.com/problems/range-sum-query-mutable/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (Segment Tree) ---
// Time Complexity: O(log N) for update and query
// Space Complexity: O(N)
class NumArray {
    vector<int> tree;
    int n;
    
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << "Sum: " << obj->sumRange(0, 2) << endl; // 9
    obj->update(1, 2);
    cout << "Sum: " << obj->sumRange(0, 2) << endl; // 8
    return 0;
}

















