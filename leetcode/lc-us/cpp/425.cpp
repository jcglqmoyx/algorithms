#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string> &words) {
        int n = (int) words.size(), m = (int) words[0].size();
        vector<vector<string>> res;
        if (m == 1) {
            for (auto &w: words) {
                res.push_back({w});
            }
            return res;
        }
        unordered_map<string, vector<string>> map;
        for (auto &w: words) {
            for (int len = 1; len < m; len++) {
                map[w.substr(0, len)].push_back(w);
            }
        }
        vector<string> v;
        function<void(int)> dfs = [&](int u) {
            if (u == m) {
                res.push_back(v);
                return;
            }
            string s;
            for (int i = 0; i < u; i++) s.push_back(v[i][u]);
            for (auto &w: map[s]) {
                v.push_back(w);
                dfs(u + 1);
                v.pop_back();
            }
        };
        for (int i = 0; i < n; i++) {
            v.push_back(words[i]);
            string t;
            t.push_back(words[i][1]);
            for (auto &w: map[t]) {
                v.push_back(w);
                dfs(2);
                v.pop_back();
            }
            v.pop_back();
        }
        return res;
    }
};