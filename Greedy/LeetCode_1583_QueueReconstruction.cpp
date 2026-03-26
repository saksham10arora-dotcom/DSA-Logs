```cpp
// LeetCode problem 1583: Unattended Queue Reconstruction, https://leetcode.com/problems/unattended-queue-reconstruction/
// Given the number of people and a list of their heights and positions in the queue, reconstruct the queue.

// Brute force approach: Try all permutations of the people and check if the given conditions are satisfied. O(n!)
// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         // Generate all permutations of the people
//         vector<vector<int>> result;
//         do {
//             // Check if the current permutation satisfies the conditions
//             if (isValid(people)) {
//                 result = people;
//                 break;
//             }
//         } while (next_permutation(people.begin(), people.end()));
//         return result;
//     }
// 
//     bool isValid(vector<vector<int>>& people) {
//         for (int i = 0; i < people.size(); i++) {
//             int count = 0;
//             for (int j = 0; j < i; j++) {
//                 if (people[j][0] >= people[i][0]) {
//                     count++;
//                 }
//             }
//             if (count != people[i][1]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// Optimal solution: Sort the people by height in descending order and then by position in ascending order. O(n^2)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort the people by height in descending order and then by position in ascending order
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> result;
        for (const auto& person : people) {
            // Insert the person at the correct position
            result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1:
    vector<vector<int>> people1 = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> result1 = solution.reconstructQueue(people1);
    for (const auto& person : result1) {
        for (int val : person) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Test case 2:
    vector<vector<int>> people2 = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    vector<vector<int>> result2 = solution.reconstructQueue(people2);
    for (const auto& person : result2) {
        for (int val : person) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Test case 3:
    vector<vector<int>> people3 = {{5,0},{5,1},{5,2},{5,3},{5,4}};
    vector<vector<int>> result3 = solution.reconstructQueue(people3);
    for (const auto& person : result3) {
        for (int val : person) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```