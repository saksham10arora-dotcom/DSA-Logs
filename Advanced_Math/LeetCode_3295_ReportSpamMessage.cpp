```cpp
// LeetCode problem 3295: Report Spam Message
// https://leetcode.com/problems/report-spam-message/
// Given a list of messages, report the spam messages.

#include <iostream>
#include <vector>
#include <string>

// Brute force approach: O(n*m) where n is the number of messages and m is the average length of a message
class Solution_BruteForce {
public:
    std::vector<std::string> reportSpamMessages(std::vector<std::string>& messages) {
        std::vector<std::string> spamMessages;
        for (const auto& message : messages) {
            if (message.find("spam") != std::string::npos) {
                spamMessages.push_back(message);
            }
        }
        return spamMessages;
    }
};

// Optimal solution: O(n*m) where n is the number of messages and m is the average length of a message
class Solution_Optimal {
public:
    std::vector<std::string> reportSpamMessages(std::vector<std::string>& messages) {
        std::vector<std::string> spamMessages;
        for (const auto& message : messages) {
            if (message.find("spam") != std::string::npos) {
                spamMessages.push_back(message);
            }
        }
        return spamMessages;
    }
};

int main() {
    Solution_BruteForce bruteForce;
    Solution_Optimal optimal;

    std::vector<std::string> messages1 = {"Hello", "This is spam", "Goodbye"};
    std::vector<std::string> messages2 = {"This is not spam", "This is spam", "This is spam again"};
    std::vector<std::string> messages3 = {"No spam here", "No spam here either"};

    std::vector<std::string> result1 = bruteForce.reportSpamMessages(messages1);
    std::vector<std::string> result2 = optimal.reportSpamMessages(messages2);
    std::vector<std::string> result3 = bruteForce.reportSpamMessages(messages3);

    std::cout << "Brute force result 1: ";
    for (const auto& message : result1) {
        std::cout << message << " ";
    }
    std::cout << std::endl;

    std::cout << "Optimal result 2: ";
    for (const auto& message : result2) {
        std::cout << message << " ";
    }
    std::cout << std::endl;

    std::cout << "Brute force result 3: ";
    for (const auto& message : result3) {
        std::cout << message << " ";
    }
    std::cout << std::endl;

    return 0;
}
```