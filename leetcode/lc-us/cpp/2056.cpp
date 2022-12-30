#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCombinations(vector<string> &pieces, vector<vector<int>> &positions) {
        n = (int) pieces.size(), pc = pieces, pt = positions;
        dfs(0);
        return ans;
    }

private:
    int n, ans = 0;
    vector<vector<int>> path;
    vector<string> pc;
    vector<vector<int>> pt;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int p[5][2];

    bool check() {
        for (int i = 0; i < n; i++) p[i][0] = pt[i][0], p[i][1] = pt[i][1];
        for (int i = 1;; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                int d = path[j][0], t = path[j][1];
                if (i <= t) {
                    flag = false;
                    p[j][0] += dx[d], p[j][1] += dy[d];
                }
            }
            if (flag) break;
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (p[j][0] == p[k][0] && p[j][1] == p[k][1]) return false;
                }
            }
        }
        return true;
    }

    void dfs(int u) {
        if (u == n) {
            if (check()) ans++;
            return;
        }

        path.push_back({0, 0});
        dfs(u + 1);
        path.pop_back();

        char type = pc[u][0];
        for (int i = 0; i < 8; i++) {
            if (type == 'r' && i % 2 || type == 'b' && i % 2 == 0) continue;
            int x = pt[u][0], y = pt[u][1];
            for (int j = 1;; j++) {
                x += dx[i], y += dy[i];
                if (x < 1 || x > 8 || y < 1 || y > 8) break;
                path.push_back({i, j});
                dfs(u + 1);
                path.pop_back();
            }
        }
    }
};