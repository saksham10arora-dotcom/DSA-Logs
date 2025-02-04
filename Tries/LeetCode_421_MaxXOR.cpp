/**
 * Problem: Maximum XOR of Two Numbers in an Array (LeetCode 421)
 * Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* links[2];
    bool containsKey(int bit) { return links[bit] != NULL; }
    void put(int bit, Node* node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }
};

class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for (int x : nums) trie.insert(x);
    int maxi = 0;
    for (int x : nums) maxi = max(maxi, trie.getMax(x));
    return maxi;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Max XOR: " << findMaximumXOR(nums) << endl;
    return 0;
}



















