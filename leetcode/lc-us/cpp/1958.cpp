#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color) {
        const int n = 8;
        int dx[n] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[n] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int i = 0; i < n; i++) {
            int x = rMove + dx[i], y = cMove + dy[i];
            while (x >= 0 && y >= 0 && x < n && y < n) {
                if (board[x][y] != '.' && board[x][y] != color) x += dx[i], y += dy[i];
                else break;
                if (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == color) return true;
            }
        }
        return false;
    }
};