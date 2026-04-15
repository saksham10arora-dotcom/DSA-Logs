```cpp
// LeetCode problem 1311: Get Watched Videos By Your Friends, https://leetcode.com/problems/get-watched-videos-by-your-friends/
// There are n people, and each person has a list of their friends. Given two integers person and k, return the list of watched videos of the kth friend of person.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// Brute force approach with O(n^2) complexity
std::vector<std::string> watchedVideosByFriendsBruteForce(std::vector<std::vector<std::string>>& watchedVideos, std::vector<std::vector<int>>& friends, int person, int k) {
    std::unordered_set<int> friendsSet;
    std::vector<int> friendsList;
    std::function<void(int, int)> dfs = [&](int person, int depth) {
        if (depth == k) {
            friendsList.push_back(person);
            return;
        }
        for (int friendId : friends[person]) {
            if (friendsSet.find(friendId) == friendsSet.end()) {
                friendsSet.insert(friendId);
                dfs(friendId, depth + 1);
            }
        }
    };
    dfs(person, 0);
    std::unordered_map<std::string, int> videoCount;
    for (int friendId : friendsList) {
        for (const std::string& video : watchedVideos[friendId]) {
            videoCount[video]++;
        }
    }
    std::vector<std::pair<std::string, int>> videoList(videoCount.begin(), videoCount.end());
    std::sort(videoList.begin(), videoList.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    std::vector<std::string> result;
    for (const auto& video : videoList) {
        result.push_back(video.first);
    }
    return result;
}

// Optimal solution with O(n + m) complexity
std::vector<std::string> watchedVideosByFriends(std::vector<std::vector<std::string>>& watchedVideos, std::vector<std::vector<int>>& friends, int person, int k) {
    std::unordered_set<int> visited;
    std::vector<int> friendsList;
    std::function<void(int, int)> dfs = [&](int person, int depth) {
        if (depth == k) {
            friendsList.push_back(person);
            return;
        }
        for (int friendId : friends[person]) {
            if (visited.find(friendId) == visited.end()) {
                visited.insert(friendId);
                dfs(friendId, depth + 1);
            }
        }
    };
    dfs(person, 0);
    std::unordered_map<std::string, int> videoCount;
    for (int friendId : friendsList) {
        for (const std::string& video : watchedVideos[friendId]) {
            videoCount[video]++;
        }
    }
    std::vector<std::pair<std::string, int>> videoList(videoCount.begin(), videoCount.end());
    std::sort(videoList.begin(), videoList.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    std::vector<std::string> result;
    for (const auto& video : videoList) {
        result.push_back(video.first);
    }
    return result;
}

int main() {
    std::vector<std::vector<std::string>> watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
    std::vector<std::vector<int>> friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    int person = 0;
    int k = 1;
    std::vector<std::string> result = watchedVideosByFriends(watchedVideos, friends, person, k);
    for (const std::string& video : result) {
        std::cout << video << " ";
    }
    std::cout << std::endl;

    watchedVideos = {{"A", "B", "C"}, {"B", "C", "D"}, {"A"}, {"A", "B", "C", "D"}};
    friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    person = 1;
    k = 2;
    result = watchedVideosByFriends(watchedVideos, friends, person, k);
    for (const std::string& video : result) {
        std::cout << video << " ";
    }
    std::cout << std::endl;

    watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
    friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    person = 0;
    k = 2;
    result = watchedVideosByFriends(watchedVideos, friends, person, k);
    for (const std::string& video : result) {
        std::cout << video << " ";
    }
    std::cout << std::endl;

    return 0;
}
```