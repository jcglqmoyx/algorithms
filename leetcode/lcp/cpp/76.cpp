#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long getSchemeCount(int n, int m, vector<string> &a) {
        if (n < m) {
            swap(n, m);
            vector<string> b(n, "");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) b[i].push_back(a[j][i]);
            }
            a = b;
        }

        const int X = 0, R = 1, B = 2, R2 = 3, B2 = 4, RB = 5, BR = 6;
        int g[7][7];
        memset(g, -1, sizeof(g));
        for (int i = 0; i < 7; ++i) g[i][0] = i;

        g[X][R] = R;
        g[X][B] = B;
        g[R][R] = R2;
        g[R][B] = RB;
        g[B][R] = BR;
        g[B][B] = B2;
        g[R2][R] = R2;
        g[B2][B] = B2;
        g[RB][R] = BR;
        g[BR][B] = RB;

        int N = 1;
        for (int i = 0; i < m; ++i) N *= 7;
        long long f[n + 1][m][N][7];
        memset(f, 0, sizeof(f));
        f[0][0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int ni = i, nj = j + 1;
                if (nj == m) ni++, nj = 0;
                int xp = -1;
                if (a[i][j] == 'R') xp = R;
                if (a[i][j] == 'B') xp = B;
                if (a[i][j] == '.') xp = 0;
                int base = 1;
                for (int x = 0; x < j; ++x) base *= 7;
                for (int h = 0; h < N; ++h) {
                    int st = h / base;
                    st = st % 7;
                    for (int c = 0; c < 7; ++c) {
                        for (int ne = 0; ne < 3; ++ne) {
                            if (xp == -1 || xp == ne) {
                                if (g[st][ne] != -1 && g[c][ne] != -1) {
                                    int nh = h + (g[st][ne] - st) * base;
                                    int nc = g[c][ne];
                                    if (ni != i) nc = 0;
                                    f[ni][nj][nh][nc] += f[i][j][h][c];
                                }
                            }
                        }
                    }
                }
            }
        }

        long long res = 0;
        for (int h = 0; h < N; ++h) {
            res += f[n][0][h][0];
        }

        return res;
    }
};