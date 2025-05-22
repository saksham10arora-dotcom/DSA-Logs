/**
 * Problem: Top K Frequent Elements (LeetCode 347)
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// --- Optimal Solution (Heap + Hash Map) ---
// Time Complexity: O(N log K)
// Space Complexity: O(N)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
    for (auto& it : freq) {
        minpq.push({it.second, it.first});
        if (minpq.size() > k) minpq.pop();
    }
    
    vector<int> res;
    while (!minpq.empty()) {
        res.push_back(minpq.top().second);
        minpq.pop();
    }
    return res;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

















