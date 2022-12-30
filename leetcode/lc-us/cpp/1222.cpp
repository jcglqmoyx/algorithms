#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int board[8][8];
        memset(board, 0, sizeof board);
        for (auto &queen: queens) {
            board[queen[0]][queen[1]] = 1;
        }
        vector<vector<int>> res;
        for (int i = 0; i < 8; i++) {
            int x = king[0], y = king[1];
            while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                if (board[x][y] == 1) {
                    res.push_back({x, y});
                    break;
                }
                x += dx[i];
                y += dy[i];
            }
        }
        return res;
    }
};