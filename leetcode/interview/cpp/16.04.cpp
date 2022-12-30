#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string tictactoe(vector<string> &board) {
        int n = (int) board.size();
        int a = n * 'X', b = n * 'O';
        int sum = 0;
        int d1 = 0, d2 = 0;
        for (int i = 0; i < n; i++) {
            int row = 0, col = 0;
            d1 += board[i][i];
            d2 += board[i][n - i - 1];
            for (int j = 0; j < n; j++) {
                row += board[i][j];
                col += board[j][i];
                sum += board[i][j];
            }
            if (row == a || col == a) {
                return "X";
            } else if (row == b || col == b) {
                return "O";
            }
        }
        if (d1 == a || d2 == a) return "X";
        if (d1 == b || d2 == b) return "O";
        if (sum == n * n / 2 * ('X' + 'O') || sum == n * n / 2 * ('X' + 'O') + 'X' ||
            sum == n * n / 2 * ('X' + 'O') + 'O')
            return "Draw";
        else return "Pending";
    }
};