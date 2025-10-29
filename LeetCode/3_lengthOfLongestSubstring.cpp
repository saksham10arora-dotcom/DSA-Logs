#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; // To store last index of each character
        int start = 0, maxLen = 0;

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            // If the character is inside the current window
            if (lastSeen.count(currentChar) && lastSeen[currentChar] >= start) {
                start = lastSeen[currentChar] + 1; // Move start to avoid duplicate
            }
            lastSeen[currentChar] = end; // Update last seen index
            maxLen = max(maxLen, end - start + 1); // Update max length
        }

        return maxLen;
    }
};
