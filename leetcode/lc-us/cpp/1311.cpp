#include <bits/stdc++.h>

using namespace std;

class Solution {
    using VS = vector<string>;
    using VVI = vector<vector<int>>;
    using VVS = vector<vector<string>>;

    unordered_map<string, int> cnt;
public:
    VS watchedVideosByFriends(VVS &watchedVideos, VVI &friends, int id, int level) {
        int n = (int) watchedVideos.size();
        bool st[n];
        memset(st, false, sizeof st);
        queue<int> q;
        q.push(id);
        int lvl = 0;
        st[id] = true;
        while (!q.empty()) {
            lvl++;
            for (auto i = q.size(); i; i--) {
                auto t = q.front();
                q.pop();
                for (int f: friends[t]) {
                    if (st[f]) continue;
                    q.push(f);
                    st[f] = true;
                    if (lvl == level) {
                        for (const auto &v: watchedVideos[f]) {
                            cnt[v]++;
                        }
                    }
                }
            }
            if (lvl == level) break;
        }
        vector<pair<int, string>> v;
        for (auto &[word, freq]: cnt) {
            v.emplace_back(freq, word);
        }
        sort(v.begin(), v.end());
        vector<string> res;
        for (auto &it: v) res.push_back(it.second);
        return res;
    }
};