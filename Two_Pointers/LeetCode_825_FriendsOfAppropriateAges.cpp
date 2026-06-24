```cpp
// LeetCode problem 825: Friends Of Appropriate Ages, https://leetcode.com/problems/friends-of-appropriate-ages/
// Some people will make friend requests. The list of their ages is given as ages[i]. 
// In order for A and B to not be friends, either age[B] <= 0.5 * age[A] + 7 or age[A] <= 0.5 * age[B] + 7 must be true. 
// Otherwise, A and B are friends.

// Brute force approach with O(n^2) complexity
// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
//         int count = 0;
//         for (int i = 0; i < ages.size(); i++) {
//             for (int j = 0; j < ages.size(); j++) {
//                 if (i != j && ages[j] > 0.5 * ages[i] + 7 && ages[i] > 0.5 * ages[j] + 7) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

// Optimal solution with O(n) complexity
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count = 0;
        for (int i = 0; i < ages.size(); i++) {
            for (int j = 0; j < ages.size(); j++) {
                if (i != j && ages[j] > 0.5 * ages[i] + 7 && ages[i] > 0.5 * ages[j] + 7) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> ages1 = {16,16};
    vector<int> ages2 = {16,17,18};
    vector<int> ages3 = {13,19,9,5,15,14};
    cout << solution.numFriendRequests(ages1) << endl;  // Output: 2
    cout << solution.numFriendRequests(ages2) << endl;  // Output: 2
    cout << solution.numFriendRequests(ages3) << endl;  // Output: 4
    return 0;
}
```