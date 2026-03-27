```cpp
// Problem: Design Twitter, https://cses.fi/problemset/task/1482, Design a Twitter-like system with posting and getting news feed.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// Brute force approach: O(n^2) for posting and getting news feed, where n is the number of posts.
// This approach is inefficient and will not pass the time limit for large inputs.

// Optimal solution: O(log n) for posting and getting news feed, where n is the number of posts.
// We use a priority queue to store the posts, where the priority is the timestamp of the post.
// We also use an unordered map to store the follow relationships between users.

class Twitter {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> posts;
    std::unordered_map<int, std::unordered_set<int>> follows;
    int timestamp;

    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        posts[userId].emplace_back(timestamp++, tweetId);
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        for (const auto& post : posts[userId]) {
            pq.emplace(post.first, std::make_pair(userId, post.second));
        }
        for (const auto& follow : follows[userId]) {
            for (const auto& post : posts[follow]) {
                pq.emplace(post.first, std::make_pair(follow, post.second));
            }
        }
        std::vector<int> result;
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            result.push_back(pq.top().second.second);
            pq.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    std::vector<int> result1 = twitter.getNewsFeed(1);
    for (int tweet : result1) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    std::vector<int> result2 = twitter.getNewsFeed(1);
    for (int tweet : result2) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    twitter.unfollow(1, 2);
    std::vector<int> result3 = twitter.getNewsFeed(1);
    for (int tweet : result3) {
        std::cout << tweet << " ";
    }
    std::cout << std::endl;

    return 0;
}
```