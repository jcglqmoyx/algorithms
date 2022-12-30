#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int m = (int) mat.size(), n = (int) mat[0].size();
        vector<int> res;
        res.reserve(m * n);
        int x = 0, y = 0;
        int dx[2] = {-1, 1}, dy[2] = {1, -1};
        int d = 0;
        while (res.size() < m * n) {
            while (x < 0 || x >= m || y < 0 || y >= n) {
                x += dx[d];
                y += dy[d];
            }
            res.push_back(mat[x][y]);
            x += dx[d];
            y += dy[d];
            if (x < 0 || y < 0 || x >= m || y >= n) {
                d = (d + 1) % 2;
                y++;
            }
        }
        return res;
    }
};