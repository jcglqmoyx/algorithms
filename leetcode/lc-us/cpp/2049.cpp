#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;
    using PII = pair<int, int>;
    int n;
    vector<int> p;
    unordered_map<int, PII> son;
    unordered_map<int, LL> cnt;

    int dfs(int u) {
        if (cnt[u]) return (int) cnt[u];
        int x = son[u].first, y = son[u].second;
        if (x == -1 && y == -1) return 1;
        int res;
        if (x != -1 && y != -1) {
            res = dfs(x) + dfs(y) + 1;
        } else if (x != -1) res = dfs(x) + 1;
        else res = dfs(y) + 1;
        return res;
    }

public:
    int countHighestScoreNodes(vector<int> &parents) {
        n = (int) parents.size(), p = parents;
        for (int i = 0; i < n; i++) son[i] = {-1, -1}, cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            if (son[p[i]].first == -1) son[p[i]].first = i;
            else son[p[i]].second = i;
        }
        for (int i = 0; i < n; i++) cnt[i] = dfs(i);
        LL mx = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            LL x = cnt[son[i].first], y = cnt[son[i].second];
            LL score;
            if (i == 0) {
                if (x && y) score = x * y;
                else if (x) score = x;
                else score = y;
            } else {
                score = 1;
                if (x) score = x;
                if (y) score *= y;
                if (n - 1 - x - y) score *= n - 1 - x - y;
            }
            if (score > mx) {
                res = 1;
                mx = score;
            } else if (score == mx) {
                res++;
            }
        }
        return res;
    }
};