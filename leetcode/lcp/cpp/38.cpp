#include <bits/stdc++.h>

using namespace std;

int f[10010][4][4];

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0},
                                       {1,  0},
                                       {0,  -1},
                                       {0,  1}};

    int check(const vector<string> &grid) {
        int n = (int) grid[0].size();
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto dir: dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < 2 && nj >= 0 && nj < n) {
                        if (grid[i][j] == 'C' && grid[ni][nj] == 'S') {
                            return INT_MAX;
                        }
                        if (grid[i][j] == 'S' && grid[ni][nj] == 'C') {
                            return INT_MAX;
                        }
                    }
                }
            }
        }

        memset(f, 0x3f, sizeof(f));
        f[0][0][0] = 0;
        unordered_map<char, int> rep = {{'.', 0},
                                        {'C', 1},
                                        {'S', 2},
                                        {'#', 3}};

        auto update = [&](int i, int s1, int s2, int t1, int t2, int extra) {
            if (s1 == 1 || s1 == 2) {
                if (s1 + t1 == 3) {
                    return;
                }
                if (t1 == 0) {
                    t1 = s1;
                }
            }
            if (s2 == 1 || s2 == 2) {
                if (s2 + t2 == 3) {
                    return;
                }
                if (t2 == 0) {
                    t2 = s2;
                }
            }
            if ((t1 == 1 || t1 == 2) && (t1 + t2 == 3)) {
                return;
            }
            if ((t1 == 1 || t1 == 2) && t2 == 0) {
                t2 = t1;
            }
            if ((t2 == 1 || t2 == 2) && t1 == 0) {
                t1 = t2;
            }
            f[i][t1][t2] = min(f[i][t1][t2], f[i - 1][s1][s2] + extra);
        };

        for (int i = 1; i <= n; ++i) {
            int t1 = rep[grid[0][i - 1]];
            int t2 = rep[grid[1][i - 1]];
            for (int s1 = 0; s1 < 4; ++s1) {
                for (int s2 = 0; s2 < 4; ++s2) {
                    update(i, s1, s2, t1, t2, 0);
                    if (grid[0][i - 1] == '.') {
                        update(i, s1, s2, 3, t2, 1);
                    }
                    if (grid[1][i - 1] == '.') {
                        update(i, s1, s2, t1, 3, 1);
                    }
                    if (grid[0][i - 1] == '.' && grid[1][i - 1] == '.') {
                        update(i, s1, s2, 3, 3, 2);
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                ans = min(ans, f[n][i][j]);
            }
        }
        return ans;
    }

public:
    int guardCastle(vector<string> &grid) {
        int n = (int) grid[0].size();
        int ans = INT_MAX;

        auto g1 = grid;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g1[i][j] == 'P') {
                    g1[i][j] = 'C';
                }
            }
        }
        ans = min(ans, check(g1));

        auto g2 = grid;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g2[i][j] == 'P') {
                    g2[i][j] = 'S';
                }
            }
        }
        ans = min(ans, check(g2));

        if (ans == INT_MAX) {
            ans = -1;
        }
        return ans;
    }
};