```cpp
// LeetCode problem 912: Sort An Array, https://leetcode.com/problems/sort-an-array/
// Given an array of integers, sort the array in ascending order.

// Brute force approach: Using built-in sort function, O(n log n) complexity
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Optimal solution: Using quicksort algorithm, O(n log n) complexity on average
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quicksort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivot = partition(nums, low, high);
            quicksort(nums, low, pivot - 1);
            quicksort(nums, pivot + 1, high);
        }
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};

int main() {
    Solution solution;
    vector<int> test1 = {5, 2, 3, 1};
    vector<int> result1 = solution.sortArray(test1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> test2 = {1, 2, 3, 4, 5};
    vector<int> result2 = solution.sortArray(test2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> test3 = {5, 4, 3, 2, 1};
    vector<int> result3 = solution.sortArray(test3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```