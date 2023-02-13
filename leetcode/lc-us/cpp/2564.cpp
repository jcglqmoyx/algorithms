#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries) {
        vector<vector<int>> res;
        auto get_length = [](int x) {
            int res = 0;
            while (x) {
                x >>= 1;
                res++;
            }
            return res;
        };

        unordered_map<int, int> S;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (!S.count(0)) S[0] = i;
                continue;
            }
            int j = i;
            int num = 0;
            while (j < s.size() && j < i + 30) {
                num = num * 2 + s[j] - '0';
                if (!S.count(num)) S[num] = i;
                j++;
            }
        }

        for (auto &q: queries) {
            int a = q[0], b = q[1];
            int want = a ^ b;
            int len = get_length(want);
            if (want == 0) {
                if (S.count(0)) res.push_back({S[0], S[0]});
                else res.push_back({-1, -1});
            } else {
                if (S.count(want)) res.push_back({S[want], S[want] + len - 1});
                else res.push_back({-1, -1});
            }
        }
        return res;
    }
};