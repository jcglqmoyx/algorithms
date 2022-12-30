#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ballGame(int num, vector<string> &plate) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

        int n = (int) plate.size(), m = (int) plate[0].size();

        function<bool(int, int, int)> check = [&](int x, int y, int d) -> bool {
            if (plate[x][y] != '.') return false;
            int t = num;
            while (t) {
                if (plate[x][y] == 'W') {
                    d = (d + 1) % 4;
                } else if (plate[x][y] == 'E') {
                    d = (d + 3) % 4;
                }
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx == n || ny < 0 || ny == m) break;
                if (plate[nx][ny] == 'O') return true;
                x = nx, y = ny;
                t--;
            }
            return false;
        };
        vector<vector<int>> res;
        for (int i = 1; i < n - 1; i++) {
            if (check(i, 0, 1)) {
                res.push_back({i, 0});
            }
            if (check(i, m - 1, 3)) {
                res.push_back({i, m - 1});
            }
        }
        for (int j = 1; j < m - 1; j++) {
            if (check(0, j, 0)) {
                res.push_back({0, j});
            }
            if (check(n - 1, j, 2)) {
                res.push_back({n - 1, j});
            }
        }
        return res;
    }
};