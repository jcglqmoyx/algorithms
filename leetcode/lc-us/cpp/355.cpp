#include <bits/stdc++.h>

using namespace std;

class Twitter {
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> followee;
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> q;
        followee[userId].insert(userId);
        for (int user: followee[userId]) {
            for (pair<int, int> &tweet: tweets[user]) {
                q.push(tweet);
            }
        }
        vector<int> res;
        for (int i = 0; i < 10 && !q.empty(); i++) {
            pair<int, int> tweet = q.top();
            q.pop();
            res.push_back(tweet.second);
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followee[followerId].erase(followeeId);
    }
};