#include <bits/stdc++.h>

using namespace std;

class Solution {
    const char STONE = '#', OBSTACLE = '*', EMPTY = '.';
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        int m = box.size(), n = box[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == STONE) {
                    int k = j + 1;
                    while (k < n && box[i][k] == EMPTY) k++;
                    box[i][j] = EMPTY;
                    box[i][k - 1] = STONE;
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = box[m - j - 1][i];
            }
        }
        return res;
    }
};