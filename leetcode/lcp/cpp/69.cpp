#include <bits/stdc++.h>

using namespace std;

class Solution {
    static const int N = 1e4 + 7;
    string ss = "helloleetcode";
    vector<string> s;
    int dp[25][N];
    vector<int> help;
    int INF = 0x3f3f3f3f;

    bool judge() {
        int o = 0;
        for (auto &i: ss) {
            o |= 1 << (i - 'a');
        }
        vector<int> cnt(26, 0);
        for (auto &w: s) {
            int u = 0;
            for (int i = 0; i < w.size(); ++i) {
                char c = w[i];
                if (o >> (c - 'a') & 1) cnt[c - 'a']++, u |= (1 << i);
            }
            help.push_back(u);
        }
        for (auto &c: ss) cnt[c - 'a']--;
        return all_of(cnt.begin(), cnt.end(), [](int x) {
            return x >= 0;
        });
    }

    int dfs(int p, int u) {
        if (p == s.size()) return u ? INF : 0;
        if (dp[p][u] != -1) return dp[p][u];
        dp[p][u] = dfs(p + 1, u);
        if (help[p] == 0) return dp[p][u];
        int m = (int) s[p].size();
        for (int i = help[p], S = help[p]; i; i = (i - 1) & S) {
            int t = u;
            bool q = true;
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    q = false;
                    for (int k = 0; k < 13; ++k) {
                        if (t >> k & 1) {
                            if (ss[k] == s[p][j]) {
                                t ^= (1 << k);
                                q = true;
                                break;
                            }
                        }
                    }
                    if (!q) break;
                }
            }
            if (!q) continue;
            int l = 0, r = m - 1;
            int ll = 0, rr = 0, lr = m - 1, rl = m - 1;
            int cost = 0;
            while (l <= r) {
                while (!(i >> l & 1)) ++l, ++ll, --lr;
                while (!(i >> r & 1)) --r, ++rr, --rl;
                if (ll < rr) {
                    cost += ll * lr;
                    ++l, --lr, --rl;
                } else {
                    cost += rr * rl;
                    --r, --rl, --lr;
                }
            }
            dp[p][u] = min(dp[p][u], dfs(p + 1, t) + cost);
        }
        return dp[p][u];
    }

public:
    int Leetcode(vector<string> &s_) {
        s = s_;
        int n = (int) s.size();
        int all = 1 << 13;
        for (int i = 0; i < n; ++i) {
            memset(dp[i], -1, all * 4);
            dp[i][0] = 0;
        }
        if (!judge()) return -1;
        return dfs(0, all - 1);
    }
};