#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string> &board) {
        const int MOD = 1e9 + 7;

        int n = (int) board.size(), m = (int) board[0].size();
        board[0][0] = board[n - 1][m - 1] = '0';
        vector<vector<int>> f(n, vector<int>(m));
        vector<vector<int>> g(n, vector<int>(m));
        g[n - 1][m - 1] = 1;
        for (int i = n - 1; ~i; i--) {
            for (int j = m - 1; ~j; j--) {
                if (board[i][j] == 'X') continue;
                int t = 0;
                if (i < n - 1) t = f[i + 1][j];
                if (j < m - 1) t = max(t, f[i][j + 1]);
                if (i < n - 1 && j < m - 1) t = max(t, f[i + 1][j + 1]);
                f[i][j] = t + board[i][j] - '0';
                if (i < n - 1 && t == f[i + 1][j]) g[i][j] = (g[i][j] + g[i + 1][j]) % MOD;
                if (j < m - 1 && t == f[i][j + 1]) g[i][j] = (g[i][j] + g[i][j + 1]) % MOD;
                if (i < n - 1 && j < m - 1 && t == f[i + 1][j + 1]) g[i][j] = (g[i][j] + g[i + 1][j + 1]) % MOD;
            }
        }
        return g[0][0] ? vector<int>{f[0][0], g[0][0]} : vector<int>{0, 0};
    }
};