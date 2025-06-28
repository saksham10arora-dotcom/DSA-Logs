```cpp
// Codeforces_514E_CountOfRangeSum, https://codeforces.com/contest/514/problem/E
// Given an array of integers and a range [lower, upper], count the number of subarrays 
// where the sum of the elements falls within the given range.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
int bruteForceCountOfRangeSum(std::vector<int>& nums, int lower, int upper) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            if (sum >= lower && sum <= upper) {
                count++;
            }
        }
    }
    return count;
}

// Optimal solution with O(n log n) complexity using modified merge sort
struct Node {
    int sum;
    int count;
};

void merge(std::vector<Node>& nodes, int left, int mid, int right, int lower, int upper) {
    std::vector<Node> leftNodes(nodes.begin() + left, nodes.begin() + mid + 1);
    std::vector<Node> rightNodes(nodes.begin() + mid + 1, nodes.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < leftNodes.size() && j < rightNodes.size()) {
        if (leftNodes[i].sum <= rightNodes[j].sum) {
            nodes[k++] = leftNodes[i++];
        } else {
            nodes[k++] = rightNodes[j++];
        }
    }
    while (i < leftNodes.size()) {
        nodes[k++] = leftNodes[i++];
    }
    while (j < rightNodes.size()) {
        nodes[k++] = rightNodes[j++];
    }
    int count = 0;
    for (int i = left; i <= mid; i++) {
        int sum = nodes[i].sum;
        int leftIndex = mid + 1, rightIndex = right;
        while (leftIndex <= rightIndex) {
            int midIndex = (leftIndex + rightIndex) / 2;
            if (nodes[midIndex].sum - sum < lower) {
                leftIndex = midIndex + 1;
            } else if (nodes[midIndex].sum - sum > upper) {
                rightIndex = midIndex - 1;
            } else {
                count += nodes[midIndex].count;
                break;
            }
        }
    }
    for (int i = left; i <= right; i++) {
        nodes[i].count = count;
    }
}

void mergeSort(std::vector<Node>& nodes, int left, int right, int lower, int upper) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(nodes, left, mid, lower, upper);
        mergeSort(nodes, mid + 1, right, lower, upper);
        merge(nodes, left, mid, right, lower, upper);
    }
}

int optimalCountOfRangeSum(std::vector<int>& nums, int lower, int upper) {
    std::vector<Node> nodes;
    nodes.push_back({0, 1});
    for (int num : nums) {
        std::vector<Node> newNodes;
        for (Node node : nodes) {
            newNodes.push_back({node.sum + num, node.count});
        }
        nodes = newNodes;
    }
    mergeSort(nodes, 0, nodes.size() - 1, lower, upper);
    int count = 0;
    for (Node node : nodes) {
        count += node.count;
    }
    return count;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    int lower1 = 3, upper1 = 7;
    std::cout << "Brute force count: " << bruteForceCountOfRangeSum(nums1, lower1, upper1) << std::endl;
    std::cout << "Optimal count: " << optimalCountOfRangeSum(nums1, lower1, upper1) << std::endl;

    std::vector<int> nums2 = {-2, 5, -1};
    int lower2 = -2, upper2 = 2;
    std::cout << "Brute force count: " << bruteForceCountOfRangeSum(nums2, lower2, upper2) << std::endl;
    std::cout << "Optimal count: " << optimalCountOfRangeSum(nums2, lower2, upper2) << std::endl;

    std::vector<int> nums3 = {1, 1, 1, 1, 1};
    int lower3 = 3, upper3 = 5;
    std::cout << "Brute force count: " << bruteForceCountOfRangeSum(nums3, lower3, upper3) << std::endl;
    std::cout << "Optimal count: " << optimalCountOfRangeSum(nums3, lower3, upper3) << std::endl;

    return 0;
}
```