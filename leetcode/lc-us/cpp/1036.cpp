#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;
    using PII = pair<int, int>;

    const int N = 1e6;
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

    bool check(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target, int limit) {
        auto hash_fn = [fn = hash<LL>()](const PII &o) -> size_t {
            auto&[x, y] = o;
            return fn((LL) x << 20 | y);
        };
        unordered_set<PII, decltype(hash_fn)> vis(0, hash_fn);
        for (const auto &pos: blocked) {
            vis.emplace(pos[0], pos[1]);
        }
        vis.emplace(source[0], source[1]);
        queue<PII> q;
        q.emplace(source[0], source[1]);
        int cnt = 0;
        while (!q.empty()) {
            for (size_t it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                cnt++;
                if (cnt > limit) return true;
                int x = t.first, y = t.second;
                for (int i = 0; i < 4; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a == N || b < 0 || b == N || vis.count({a, b})) continue;
                    if (a == target[0] && b == target[1]) return true;
                    q.emplace(a, b);
                    vis.emplace(a, b);
                }
            }
        }
        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
        int n = (int) blocked.size();
        int limit = n * (n - 1) / 2;
        return check(blocked, source, target, limit) && check(blocked, target, source, limit);
    }
};