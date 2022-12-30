#include <bits/stdc++.h>

using namespace std;

class Solution {
    const char BLANK = '.', BLACK = 'X', WHITE = 'O';
    int n{}, m{};
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    bool first_search{};

    bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int get(vector<string> &board, int x, int y) {
        int cnt = 0;
        if (first_search) {
            first_search = false;
            for (int idx = 0; idx < 8; idx++) {
                int a = x + dx[idx], b = y + dy[idx];
                while (check(a, b) && board[a][b] == WHITE) a += dx[idx], b += dy[idx];
                if (check(a, b) && board[a][b] == BLACK) {
                    int dt = max(abs(a - x), abs(b - y)) - 1;
                    cnt += dt;
                    for (int step = 1; step <= dt; step++) {
                        int row = x + dx[idx] * step, col = y + dy[idx] * step;
                        board[row][col] = BLACK;
                    }
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == BLACK) {
                        for (int idx = 0; idx < 8; idx++) {
                            int a = i + dx[idx], b = j + dy[idx];
                            while (check(a, b) && board[a][b] == WHITE) a += dx[idx], b += dy[idx];
                            if (check(a, b) && board[a][b] == BLACK) {
                                int dt = max(abs(a - i), abs(b - j)) - 1;
                                cnt += dt;
                                for (int step = 1; step <= dt; step++) {
                                    int row = i + dx[idx] * step, col = j + dy[idx] * step;
                                    board[row][col] = BLACK;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (cnt) cnt += get(board, 0, 0);
        return cnt;
    }

public:
    int flipChess(vector<string> &g) {
        n = (int) g.size(), m = (int) g[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<string> board = g;
                if (g[i][j] == BLANK) {
                    board[i][j] = BLACK;
                    first_search = true;
                    res = max(res, get(board, i, j));
                }
            }
        }
        return res;
    }
};