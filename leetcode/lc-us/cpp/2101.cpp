#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        n = (int) bombs.size();
        path.resize(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = bombs[i][0], y1 = bombs[i][1];
                int x2 = bombs[j][0], y2 = bombs[j][1];
                LL dx = x1 - x2, dy = y1 - y2;
                LL r = bombs[i][2];
                path[i][j] = dx * dx + dy * dy <= r * r;
            }
        }
        res = 0;
        for (int i = 0; i < n; i++) {
            res = max(get(i), res);
        }
        return res;
    }

private:
    using LL = long long;

    int res;
    int n;
    vector<vector<bool>> path;

    int get(int u) {
        int cnt = 0;
        queue<int> q;
        q.push(u);
        vector<bool> st(n);
        st[u] = true;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i < n; i++) {
                if (!st[i] && u != i && path[t][i]) {
                    q.push(i);
                    st[i] = true;
                }
            }
        }
        return cnt;
    }
};