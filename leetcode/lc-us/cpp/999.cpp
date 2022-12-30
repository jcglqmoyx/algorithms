#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        int n = (int) board.size(), m = (int) board[0].size();
        int x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'R') {
                    x = i, y = j;
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x, ny = y;
            while (true) {
                nx += dx[i], ny += dy[i];
                if (nx < 0 || nx == n || ny < 0 || ny == m) break;
                if (board[nx][ny] != '.') {
                    if (board[nx][ny] == 'p') res++;
                    break;
                }
            }
        }
        return res;
    }
};