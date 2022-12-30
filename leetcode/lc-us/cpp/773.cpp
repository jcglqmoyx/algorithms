#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        typedef vector<vector<int>> VVI;

        VVI target = {{1, 2, 3},
                      {4, 5, 0}};
        if (board == target) return 0;

        map<VVI, int> dist;
        dist[board] = 0;

        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

        queue<VVI> q;
        q.push(board);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int x, y;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (t[i][j] == 0) {
                        x = i, y = j;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == 2 || b < 0 || b == 3) continue;
                auto r = t;
                swap(r[a][b], r[x][y]);
                if (!dist.count(r)) {
                    dist[r] = dist[t] + 1;
                    if (r == target) return dist[r];
                    q.push(r);
                }
            }
        }
        return -1;
    }
};