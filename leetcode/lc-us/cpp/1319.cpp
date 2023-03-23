#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (n > connections.size() + 1) return -1;
        int p[n], sz[n], cnt = n;
        for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        for (auto &c: connections) {
            int x = c[0], y = c[1];
            int px = find(x), py = find(y);
            if (px != py) {
                if (sz[px] > sz[py]) swap(px, py);
                p[px] = py;
                sz[py] += sz[px];
                cnt--;
            }
        }
        return cnt - 1;
    }
};