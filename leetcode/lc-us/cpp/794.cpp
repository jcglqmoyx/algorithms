#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string> &board) {
        int x = 0, o = 0;
        for (string &row: board) {
            for (char c: row) {
                if (c == 'X') x++;
                else if (c == 'O') o++;
            }
        }
        if (x > o + 1 || o > x) return false;
        char winner = ' ';
        int horizontal = 0, vertical = 0;
        if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
            horizontal++;
            if (board[0][0] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
            horizontal++;
            if (board[1][0] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2]) {
            horizontal++;
            if (board[2][0] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
            vertical++;
            if (board[0][0] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
            vertical++;
            if (board[0][1] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
            vertical++;
            if (board[0][2] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X') {
                winner = 'X';
            } else {
                winner = 'O';
            }
        }
        if (horizontal > 1 || vertical > 1 || winner == 'X' && x == o || winner == 'O' && o < x) return false;
        return true;
    }
};