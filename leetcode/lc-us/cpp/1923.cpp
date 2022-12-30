#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static constexpr int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

    struct pair_hash {
        size_t operator()(const pair<int, int> &p) const {
            auto fn = hash<int>();
            return (fn(p.first) << 16) ^ fn(p.second);
        }
    };

    using LL = long long;

public:
    int longestCommonSubpath(int n, vector<vector<int>> &paths) {
        mt19937 gen{random_device{}()};
        auto dis = uniform_int_distribution<int>(1e6, 1e7);
        int p1 = dis(gen);
        int p2 = dis(gen);
        int m = (int) paths.size();
        auto check = [&](int len) {
            LL mul1 = 1, mul2 = 1;
            for (int i = 1; i <= len; ++i) {
                mul1 = mul1 * p1 % MOD1;
                mul2 = mul2 * p2 % MOD2;
            }
            unordered_set<pair<int, int>, pair_hash> S;
            for (int i = 0; i < m; ++i) {
                LL h1 = 0, h2 = 0;
                for (int j = 0; j < len; ++j) {
                    h1 = (h1 * p1 + paths[i][j]) % MOD1;
                    h2 = (h2 * p2 + paths[i][j]) % MOD2;
                }
                unordered_set<pair<int, int>, pair_hash> T;
                if (i == 0 || S.count({h1, h2})) T.emplace(h1, h2);
                for (int j = len; j < paths[i].size(); ++j) {
                    h1 = ((h1 * p1 % MOD1 + paths[i][j] - paths[i][j - len] * mul1 % MOD1) % MOD1 + MOD1) % MOD1;
                    h2 = ((h2 * p2 % MOD2 + paths[i][j] - paths[i][j - len] * mul2 % MOD2) % MOD2 + MOD2) % MOD2;
                    if (i == 0 || S.count({h1, h2})) T.emplace(h1, h2);
                }
                if (T.empty()) return false;
                S = move(T);
            }
            return true;
        };
        int l = 0, r = INT32_MAX;
        for (auto &path: paths) r = min(r, (int) path.size());
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};