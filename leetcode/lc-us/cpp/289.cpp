#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = (int) board.size(), n = (int) board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        if (r == i && c == j) continue;
                        if (r >= 0 && r < m && c >= 0 && c < n && (board[r][c] == 1 || board[r][c] == -1)) {
                            live++;
                        }
                    }
                }
                if (live < 2 && board[i][j] == 1) {
                    board[i][j] = -1;
                } else if (live == 3) {
                    if (board[i][j] == 0) {
                        board[i][j] = 2;
                    }
                } else if (live > 3 && board[i][j] == 1) {
                    board[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == -1) board[i][j] = 0;
            }
        }
    }
};