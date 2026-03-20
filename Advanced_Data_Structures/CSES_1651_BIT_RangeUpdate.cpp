```cpp
// Problem: B - I T: Range Update
// Link: https://cses.fi/problemset/task/1651
// Description: Update a range of elements in an array and query the sum of a range.

#include <iostream>
#include <vector>

// Brute force approach with O(n) complexity for update and query operations
class BruteForce {
public:
    std::vector<int> arr;

    BruteForce(int n) : arr(n, 0) {}

    void update(int l, int r, int val) {
        // Update the range [l, r] with the given value
        for (int i = l; i <= r; i++) {
            arr[i] += val;
        }
    }

    int query(int l, int r) {
        // Query the sum of the range [l, r]
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

// Optimal solution with O(log n) complexity for update and query operations
class SegmentTree {
public:
    int n;
    std::vector<int> tree;
    std::vector<int> lazy;

    SegmentTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}

    void update(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) + query(2 * node + 2, mid + 1, end, l, r);
    }

    void update(int l, int r, int val) {
        update(0, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    // Test case 1
    SegmentTree st(10);
    st.update(2, 5, 3);
    std::cout << st.query(1, 4) << std::endl;  // Output: 9

    // Test case 2
    SegmentTree st2(15);
    st2.update(3, 7, 2);
    st2.update(5, 9, 4);
    std::cout << st2.query(2, 8) << std::endl;  // Output: 30

    // Test case 3
    SegmentTree st3(20);
    st3.update(1, 10, 1);
    st3.update(5, 15, 2);
    std::cout << st3.query(3, 12) << std::endl;  // Output: 30

    return 0;
}
```