#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int n = (int) board.size(), m = (int) board[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        bool todo = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j]) {
                    int k = j + 1;
                    while (k < m && k - j < 3 && board[i][k] == board[i][j]) k++;
                    if (k - j == 3) {
                        todo = true;
                        for (int col = j; col < k; col++) st[i][col] = true;
                    }
                    k = i + 1;
                    while (k < n && k - i < 3 && board[k][j] == board[i][j]) k++;
                    if (k - i == 3) {
                        todo = true;
                        for (int row = i; row < k; row++) st[row][j] = true;
                    }
                }
            }
        }
        if (todo) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (st[i][j]) {
                        board[i][j] = 0;
                    }
                }
            }
            for (int i = n - 1; i; i--) {
                for (int j = 0; j < m; j++) {
                    if (!board[i][j]) {
                        vector<int> v;
                        for (int row = i - 1; ~row; row--) {
                            if (board[row][j]) v.push_back(board[row][j]);
                        }
                        if (!v.empty()) {
                            int idx = 0, row = i;
                            while (idx < v.size()) {
                                board[row][j] = v[idx];
                                row--, idx++;
                            }
                            for (row = i - (int) v.size(); ~row; row--) board[row][j] = 0;
                        }
                    }
                }
            }
            return candyCrush(board);
        } else {
            return board;
        }
    }
};