```cpp
// LeetCode problem 251: Count Smaller Advanced
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// You are given an integer array nums and you have to return a new count array.
// The count array is a count for the number of smaller elements to the right of each element in the given array.

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    count++;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};

// Optimal solution with O(n log n) complexity using Binary Indexed Tree
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ranks;
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        for (int num : nums) {
            auto it = lower_bound(copy.begin(), copy.end(), num);
            ranks.push_back(it - copy.begin() + 1);
        }
        vector<int> result(nums.size());
        vector<int> bit(nums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = query(bit, ranks[i] - 1);
            update(bit, ranks[i]);
        }
        return result;
    }

    void update(vector<int>& bit, int i) {
        i++;
        while (i < bit.size()) {
            bit[i]++;
            i += i & -i;
        }
    }

    int query(vector<int>& bit, int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {5, 2, 6, 1};
    vector<int> result1 = solution.countSmaller(nums1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    vector<int> result2 = solution.countSmaller(nums2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> result3 = solution.countSmaller(nums3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```