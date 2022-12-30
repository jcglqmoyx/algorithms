#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>> &moves) {
        if (moves.size() < 5) return "Pending";
        char chars[3][3] = {{0, 1, 2},
                            {3, 4, 5},
                            {6, 7, 8}};
        bool flag = true;
        for (vector<int> move: moves) {
            if (flag) chars[move[0]][move[1]] = 'X';
            else chars[move[0]][move[1]] = 'O';
            flag = !flag;
        }
        if (chars[0][0] == chars[1][1] && chars[1][1] == chars[2][2] ||
            chars[0][2] == chars[1][1] && chars[1][1] == chars[2][0])
            return chars[1][1] == 'X' ? "A" : "B";
        for (int i = 0; i < 3; i++) {
            if (chars[i][0] == chars[i][1] && chars[i][1] == chars[i][2])
                return chars[i][0] == 'X' ? "A" : "B";
            if (chars[0][i] == chars[1][i] && chars[1][i] == chars[2][i])
                return chars[0][i] == 'X' ? "A" : "B";
        }
        return moves.size() < 9 ? "Pending" : "Draw";
    }
};