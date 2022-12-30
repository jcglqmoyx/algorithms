#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        using ll = long long;
        int m = (int) edges.size() << 1;
        if (!m) return (ll) n * (n - 1) / 2;
        int h[n], e[m], ne[m], idx;
        bool st[n];
        memset(h, -1, sizeof h), idx = 0, memset(st, false, sizeof st);
        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
        }
        ll tot = n, res = 0;
        for (int i = 0; i < n; i++) {
            if (!st[i]) {
                queue<int> q;
                q.push(i);
                st[i] = true;
                int cnt = 1;
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for (int j = h[t]; ~j; j = ne[j]) {
                        int k = e[j];
                        if (st[k]) continue;
                        q.push(k);
                        cnt++;
                        st[k] = true;
                    }
                }
                res += (tot - cnt) * cnt, tot -= cnt;
            }
        }
        return res;
    }
};