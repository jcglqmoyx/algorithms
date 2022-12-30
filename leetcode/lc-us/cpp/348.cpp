#include <bits/stdc++.h>

using namespace std;

class TicTacToe {
    int len;
    vector<int> rows1, cols1;
    vector<int> rows2, cols2;
    int diagonal1, diagonal2, diagonal3, diagonal4;
    int mid = 0;

public:
    TicTacToe(int n) {
        len = n;
        rows1 = vector<int>(n, 0);
        cols1 = vector<int>(n, 0);
        rows2 = vector<int>(n, 0);
        cols2 = vector<int>(n, 0);
        diagonal1 = 0;
        diagonal2 = 0;
        diagonal3 = 0;
        diagonal4 = 0;
    }

    int move(int row, int col, int player) {
        if (player == 1) {
            rows1[row]++;
            if (rows1[row] == len) return 1;
            cols1[col]++;
            if (cols1[col] == len) return 1;
        } else {
            rows2[row]++;
            if (rows2[row] == len) return 2;
            cols2[col]++;
            if (cols2[col] == len) return 2;
        }
        if (row == col) {
            if (player == 1) {
                diagonal1++;
            } else {
                diagonal2++;
            }
        }
        if (row + col == len - 1) {
            if (player == 1) {
                diagonal3++;
            } else {
                diagonal4++;
            }
        }
        if (diagonal1 == len || diagonal3 == len) return 1;
        if (diagonal2 == len || diagonal4 == len) return 2;
        return 0;
    }
};