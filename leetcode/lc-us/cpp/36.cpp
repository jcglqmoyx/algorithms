#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<char> chars(9);
        for (int i = 0; i < 9; i++) {
            fill(chars.begin(), chars.end(), 0);
            for (int col = 0; col < 9; col++) {
                if (isdigit(board[col][i])) {
                    if (chars[board[col][i] - '1']) return false;
                    chars[board[col][i] - '1'] = 1;
                }
            }
            fill(chars.begin(), chars.end(), 0);
            for (int row = 0; row < 9; row++) {
                if (isdigit(board[i][row])) {
                    if (chars[board[i][row] - '1']) return false;
                    chars[board[i][row] - '1'] = 1;
                }
            }
            if (i % 3 == 0) {
                for (int j = 0; j < 9; j += 3) {
                    fill(chars.begin(), chars.end(), 0);
                    for (int m = i; m < i + 3; m++) {
                        for (int n = j; n < j + 3; n++) {
                            if (isdigit(board[m][n])) {
                                if (chars[board[m][n] - '1']) return false;
                                chars[board[m][n] - '1']++;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};