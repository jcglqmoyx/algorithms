#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole) {
        struct Node {
            int x, y;
            int d;
            string s;
        };

        int n = (int) maze.size(), m = (int) maze[0].size();

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        string directions = "dlru";

        bool f[n][m][4];
        memset(f, false, sizeof f);
        int ball_x = ball[0], ball_y = ball[1], hole_x = hole[0], hole_y = hole[1];

        auto check = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m && !maze[x][y];
        };

        string res;
        queue<Node> q;
        for (int i = 0; i < 4; i++) {
            string s;
            s.push_back(directions[i]);
            Node node = {ball_x, ball_y, i, s};
            q.push(node);
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            f[t.x][t.y][t.d] = true;
            int nx = t.x + dx[t.d], ny = t.y + dy[t.d];
            if (!check(nx, ny)) {
                for (int i = 0; i < 4; i++) {
                    if (i == t.d) {
                        continue;
                    }
                    if (i == 0 && t.d == 3 || i == 3 && t.d == 0 || i == 1 && t.d == 2 || i == 2 && t.d == 1) {
                        continue;
                    }
                    if (f[t.x][t.y][i]) {
                        continue;
                    }
                    nx = t.x + dx[i], ny = t.y + dy[i];
                    if (!check(nx, ny)) continue;
                    Node node = {nx, ny, i, t.s};

                    if (t.x == ball_x && t.y == ball_y) {
                        node.s.pop_back();
                    }
                    node.s.push_back(directions[i]);
                    q.push(node);
                    if (nx == hole_x && ny == hole_y) {
                        return node.s;
                    }
                }
            } else {
                if (f[nx][ny][t.d]) continue;
                Node node = {nx, ny, t.d, t.s};
                q.push(node);
                if (nx == hole_x && ny == hole_y) {
                    return t.s;
                }
            }
        }
        return "impossible";
    }
};