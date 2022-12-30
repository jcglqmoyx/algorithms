#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool flag = false;

    void dfs(vector<vector<char>> &board, string &word, int idx, int i, int j) {
        if (i < 0 || j < 0 || i == board.size() || j == board[i].size() || word[idx] != board[i][j]) {
            return;
        }
        if (idx == word.length() - 1) {
            flag = true;
            return;
        }
        char temp = board[i][j];
        board[i][j] = '.';
        dfs(board, word, idx + 1, i + 1, j);
        if (flag) return;
        dfs(board, word, idx + 1, i - 1, j);
        if (flag) return;
        dfs(board, word, idx + 1, i, j + 1);
        if (flag) return;
        dfs(board, word, idx + 1, i, j - 1);
        board[i][j] = temp;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.length() > board.size() * board[0].size()) return false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j]) dfs(board, word, 0, i, j);
            }
        }
        return flag;
    }
};