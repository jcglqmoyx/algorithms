#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string> &crea, vector<string> &ids, vector<int> &views) {
        vector<vector<string>> ret;
        unordered_map<string, pair<long long, int>> hash;
        long long cnt = 0;
        int n = (int) ids.size();
        for (int i = 0; i < n; i++) {
            if (!hash.count(crea[i])) {
                hash[crea[i]] = make_pair(views[i], i);
                cnt = max((long long) views[i], cnt);
            } else {
                auto &[x, y] = hash[crea[i]];
                x += views[i];
                cnt = max(x, cnt);
                if (views[i] > views[y] || (views[i] == views[y] && ids[i] < ids[y])) y = i;
            }
        }
        for (auto &[c, h]: hash) {
            auto &[x, y] = h;
            if (x < cnt) continue;
            ret.push_back({c, ids[y]});
        }
        return ret;
    }
};