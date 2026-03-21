```cpp
// Design Twitter Variant, https://leetcode.com/problems/design-twitter/
// Design a simplified version of Twitter where users can post tweets, follow/unfollow other users, and see the 10 most recent tweets in the user's news feed.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Twitter {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> followees;
    int timestamp;

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        // Brute force approach: O(1) to add a tweet, O(n) to get the 10 most recent tweets
        // Optimal solution: O(1) to add a tweet, O(log n) to get the 10 most recent tweets
        tweets[userId].emplace_back(tweetId, timestamp++);
    }

    std::vector<int> getNewsFeed(int userId) {
        // Brute force approach: O(n) to get the 10 most recent tweets
        // Optimal solution: O(log n) to get the 10 most recent tweets
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        for (const auto& tweet : tweets[userId]) {
            pq.push({tweet.second, {userId, tweet.first}});
        }
        for (const auto& followee : followees[userId]) {
            for (const auto& tweet : tweets[followee]) {
                pq.push({tweet.second, {followee, tweet.first}});
            }
        }
        std::vector<int> newsFeed;
        while (!pq.empty() && newsFeed.size() < 10) {
            newsFeed.push_back(pq.top().second.second);
            pq.pop();
        }
        return newsFeed;
    }

    void follow(int followerId, int followeeId) {
        // Brute force approach: O(1) to add a followee
        // Optimal solution: O(1) to add a followee
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // Brute force approach: O(1) to remove a followee
        // Optimal solution: O(1) to remove a followee
        followees[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.postTweet(1, 6);
    std::vector<int> newsFeed = twitter.getNewsFeed(1);
    for (const auto& tweet : newsFeed) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 7);
    newsFeed = twitter.getNewsFeed(1);
    for (const auto& tweet : newsFeed) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    twitter.unfollow(1, 2);
    newsFeed = twitter.getNewsFeed(1);
    for (const auto& tweet : newsFeed) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    return 0;
}
```