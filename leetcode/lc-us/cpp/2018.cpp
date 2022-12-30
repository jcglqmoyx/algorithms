#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>> &_board, string word) {
        n = (int) _board.size(), m = (int) _board[0].size(), len = (int) word.length(), board = _board;
        horizontal.resize(n + 1, vector<int>(m + 1)), vertical.resize(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                horizontal[i][j] = horizontal[i][j - 1];
                if (board[i - 1][j - 1] == OBSTACLE) horizontal[i][j]++;
                vertical[i][j] = vertical[i - 1][j];
                if (board[i - 1][j - 1] == OBSTACLE) vertical[i][j]++;
            }
        }
        if (can_insert_horizontally(word) || can_insert_vertically(word)) return true;
        reverse(word.begin(), word.end());
        if (can_insert_horizontally(word) || can_insert_vertically(word)) return true;
        return false;
    }

private:
    const char OBSTACLE = '#';
    int n, m, len;
    vector<vector<char>> board;
    vector<vector<int>> horizontal, vertical;

    bool can_insert_horizontally(string word) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + len > m) break;
                if (j && board[i][j - 1] != OBSTACLE) continue;
                if (horizontal[i + 1][j + len] - horizontal[i + 1][j]) continue;
                if (j + len < m && board[i][j + len] != OBSTACLE) continue;
                bool flag = true;
                for (int p = 0, q = j; p < len; p++, q++) {
                    if (board[i][q] != ' ' && board[i][q] != word[p]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }

    bool can_insert_vertically(string word) {
        for (int i = 0; i < n; i++) {
            if (i + len > n) break;
            for (int j = 0; j < m; j++) {
                if (i && board[i - 1][j] != OBSTACLE) continue;
                if (vertical[i + len][j + 1] - vertical[i][j + 1]) continue;
                if (i + len < n && board[i + len][j] != OBSTACLE) continue;
                bool flag = true;
                for (int p = 0, q = i; p < len; p++, q++) {
                    if (board[q][j] != ' ' && board[q][j] != word[p]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};