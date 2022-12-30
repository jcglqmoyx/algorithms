#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = (int) rooms.size(), n = (int) rooms[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        const int GATE = 0;
        const int INF = 2147483647;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == GATE) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto[x, y]=q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && rooms[nx][ny] == INF) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};