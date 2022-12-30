#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool flag = false;

    void dfs(vector<vector<char>> &bd, string &word, int index, int i, int j) {
        if (i < 0 || i == bd.size() || j < 0 || j == bd[i].size() || bd[i][j] != word[index] || bd[i][j] == 0) return;
        if (index == word.length() - 1) {
            flag = true;
            return;
        }
        char c = bd[i][j];
        bd[i][j] = 0;
        dfs(bd, word, index + 1, i - 1, j);
        if (flag) return;
        dfs(bd, word, index + 1, i + 1, j);
        if (flag) return;
        dfs(bd, word, index + 1, i, j - 1);
        if (flag) return;
        dfs(bd, word, index + 1, i, j + 1);
        bd[i][j] = c;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, word, 0, i, j);
                }
            }
        }
        return flag;
    }
};