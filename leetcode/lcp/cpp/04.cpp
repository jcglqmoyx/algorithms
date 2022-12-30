#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int domino(int n, int m, vector<vector<int>> &broken) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        int tot = n * m;
        bool st[tot];
        vector<int> match(tot, -1);
        vector<vector<int>> g(tot);
        vector<bool> br(tot);
        for (auto &b: broken) {
            int x = b[0], y = b[1];
            br[x * m + y] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0 && !br[i * m + j]) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x == n || y < 0 || y == m || br[x * m + y]) continue;
                        g[i * m + j].push_back(x * m + y);
                    }
                }
            }
        }
        function<bool(int)> find = [&](int u) -> bool {
            for (int x: g[u]) {
                if (!st[x]) {
                    st[x] = true;
                    if (match[x] == -1 || find(match[x])) {
                        match[x] = u;
                        return true;
                    }
                }
            }
            return false;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0 && !br[i * m + j]) {
                    memset(st, false, sizeof st);
                    if (find(i * m + j)) res++;
                }
            }
        }
        return res;
    }
};