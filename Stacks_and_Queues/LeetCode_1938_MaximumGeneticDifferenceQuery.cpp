```cpp
// Maximum Genetic Difference Query, https://leetcode.com/problems/maximum-genetic-difference-query/
// Given a list of integers representing the genetic difference between each pair of consecutive elements in a sequence,
// find the maximum genetic difference for each query.

// Brute force approach: O(n^2) - for each query, iterate through the sequence to find the maximum genetic difference
class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<int>& queries) {
        int n = parents.size();
        vector<int> result;
        for (auto& query : queries) {
            int maxDiff = 0;
            for (int i = 0; i < n; i++) {
                int diff = 0;
                int j = i;
                while (j != -1) {
                    diff ^= parents[j];
                    j = parents[j];
                }
                maxDiff = max(maxDiff, diff ^ query);
            }
            result.push_back(maxDiff);
        }
        return result;
    }
};

// Optimal solution: O(n + q) - use a Trie to store the genetic differences and query the maximum difference
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<int>& queries) {
        int n = parents.size();
        vector<int> values(n);
        for (int i = 1; i < n; i++) {
            values[i] = parents[i];
        }
        vector<pair<int, int>> queryList;
        for (int i = 0; i < queries.size(); i++) {
            queryList.emplace_back(queries[i], i);
        }
        vector<int> result(queries.size());
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++) {
            TrieNode* node = root;
            for (int j = 30; j >= 0; j--) {
                int bit = (values[i] >> j) & 1;
                if (!node->children[bit]) {
                    node->children[bit] = new TrieNode();
                }
                node = node->children[bit];
            }
        }
        for (auto& query : queryList) {
            TrieNode* node = root;
            int maxDiff = 0;
            for (int j = 30; j >= 0; j--) {
                int bit = (query.first >> j) & 1;
                if (node->children[!bit]) {
                    maxDiff |= 1 << j;
                    node = node->children[!bit];
                } else {
                    node = node->children[bit];
                }
            }
            result[query.second] = maxDiff;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> parents1 = {3, 7, 5, 6, 2, 0, 1};
    vector<int> queries1 = {5, 4, 3};
    vector<int> result1 = solution.maxGeneticDifference(parents1, queries1);
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> parents2 = {3, 7, 5, 6, 2, 0, 1};
    vector<int> queries2 = {6, 1, 3};
    vector<int> result2 = solution.maxGeneticDifference(parents2, queries2);
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> parents3 = {3, 7, 5, 6, 2, 0, 1};
    vector<int> queries3 = {1, 2, 3};
    vector<int> result3 = solution.maxGeneticDifference(parents3, queries3);
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```