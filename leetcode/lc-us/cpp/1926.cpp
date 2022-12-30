#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

using QPII = queue<pair<int, int>>;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int n = (int) maze.size(), m = (int) maze[0].size();
        vector<vector<int>> st(n, vector<int>(m));
        QPII q;
        q.push({entrance[0], entrance[1]});
        st[entrance[0]][entrance[1]] = true;
        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.x + dx[i], b = t.y + dy[i];
                    if (a < 0 || a >= n || b < 0 || b >= m) continue;
                    if (st[a][b] || maze[a][b] == '+') continue;
                    if (a == 0 || a == n - 1 || b == 0 || b == m - 1) return step;
                    st[a][b] = true;
                    q.push({a, b});
                }
            }
        }
        return -1;
    }
};