```cpp
// LeetCode problem 2713: Design Twitter Advanced
// https://leetcode.com/problems/design-twitter-advanced/
// Design a Twitter-like system where users can post tweets and follow other users.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

// Brute force approach: O(n^2) for posting a tweet and O(n^2) for getting news feed
// class TwitterAdvanced {
//     std::vector<std::vector<int>> tweets;
//     std::unordered_map<int, std::unordered_set<int>> followings;
// public:
//     void postTweet(int userId, int tweetId) {
//         tweets.push_back({userId, tweetId});
//     }
//     std::vector<int> getNewsFeed(int userId) {
//         std::vector<int> newsFeed;
//         for (auto it = tweets.rbegin(); it != tweets.rend(); ++it) {
//             if (followings[userId].count(it->at(0)) || it->at(0) == userId) {
//                 newsFeed.push_back(it->at(1));
//             }
//             if (newsFeed.size() == 10) break;
//         }
//         return newsFeed;
//     }
//     void follow(int followerId, int followeeId) {
//         followings[followerId].insert(followeeId);
//     }
//     void unfollow(int followerId, int followeeId) {
//         followings[followerId].erase(followeeId);
//     }
// };

// Optimal solution: O(log n) for posting a tweet and O(log n) for getting news feed
class TwitterAdvanced {
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> followings;
    int timestamp;
public:
    TwitterAdvanced() : timestamp(0) {}
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
        if (tweets[userId].size() > 10) tweets[userId].erase(tweets[userId].begin());
    }
    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        for (auto& followee : followings[userId]) {
            if (tweets.count(followee)) {
                for (auto& tweet : tweets[followee]) {
                    pq.emplace(tweet.first, std::make_pair(followee, tweet.second));
                }
            }
        }
        if (tweets.count(userId)) {
            for (auto& tweet : tweets[userId]) {
                pq.emplace(tweet.first, std::make_pair(userId, tweet.second));
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
        followings[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

int main() {
    TwitterAdvanced twitter;
    twitter.postTweet(1, 5);
    twitter.postTweet(1, 4);
    twitter.postTweet(2, 3);
    twitter.postTweet(2, 2);
    twitter.postTweet(2, 1);
    twitter.follow(1, 2);
    for (int tweet : twitter.getNewsFeed(1)) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;
    twitter.unfollow(1, 2);
    for (int tweet : twitter.getNewsFeed(1)) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;
    return 0;
}
```