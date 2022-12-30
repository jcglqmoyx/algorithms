#include <bits/stdc++.h>

using namespace std;

class TweetCounts {
    unordered_map<string, bool> st;
    unordered_map<string, vector<int>> hash;
public:
    TweetCounts() {
    }

    void recordTweet(string tweetName, int time) {
        hash[tweetName].push_back(time);
        st[tweetName] = false;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = 60;
        if (freq == "hour") interval = 3600;
        else if (freq == "day") interval = 86400;

        vector<int> res((endTime - startTime) / interval + 1);

        if (!hash.count(tweetName)) return res;

        auto &v = hash[tweetName];
        if (!st[tweetName]) {
            sort(v.begin(), v.end());
            st[tweetName] = true;
        }
        int n = (int) v.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (v[mid] >= startTime) r = mid;
            else l = mid + 1;
        }

        for (int i = l; i < n && v[i] <= endTime; i++) {
            res[(v[i] - startTime) / interval]++;
        }
        return res;
    }
};