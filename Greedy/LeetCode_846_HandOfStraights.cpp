/**
 * Problem: Hand of Straights (LeetCode 846)
 * Link: https://leetcode.com/problems/hand-of-straights/
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// --- Optimal Solution (Greedy with Map) ---
// Time Complexity: O(N log N)
// Space Complexity: O(N)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
    map<int, int> count;
    for (int x : hand) count[x]++;
    
    while (!count.empty()) {
        int first = count.begin()->first;
        for (int i = 0; i < groupSize; i++) {
            if (count.find(first + i) == count.end()) return false;
            if (--count[first + i] == 0) {
                count.erase(first + i);
            }
        }
    }
    return true;
}

int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    cout << (isNStraightHand(hand, groupSize) ? "True" : "False") << endl;
    return 0;
}





















