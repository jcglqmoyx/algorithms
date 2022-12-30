#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<vector<string>> shapes;
    bool A[10][10][10];
    short used[6];

    int CUBE_BASE[6][3] = {
            0, 0, 0,
            0, 0, 1,
            1, 0, 1,
            0, 0, 1,
            0, 0, 1,
            0, 1, 1
    };
    int CUBE_DIR[6][6] = {
            1, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 1, 0,
            0, 0, -1, 0, 1, 0,
            0, 0, -1, 0, 1, 0,
            0, 0, -1, 1, 0, 0,
            0, 0, -1, 1, 0, 0
    };

    int SHAPE_BASE[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
    int SHAPE_DIR[4][2] = {1, 1, 1, -1, -1, 1, -1, -1};

    bool gao(int x, int k, int s, bool rc, int modify) {
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++) {
                int i = CUBE_BASE[k][0] * (n - 1) + CUBE_DIR[k][0] * a + CUBE_DIR[k][3] * b;
                int j = CUBE_BASE[k][1] * (n - 1) + CUBE_DIR[k][1] * a + CUBE_DIR[k][4] * b;
                int z = CUBE_BASE[k][2] * (n - 1) + CUBE_DIR[k][2] * a + CUBE_DIR[k][5] * b;
                int si = SHAPE_BASE[s][0] * (n - 1) + SHAPE_DIR[s][0] * (rc ? b : a);
                int sj = SHAPE_BASE[s][1] * (n - 1) + SHAPE_DIR[s][1] * (rc ? a : b);
                if (shapes[x][si][sj] == '1') {
                    if (modify == 1) A[i][j][z] = true;
                    else if (modify == -1) A[i][j][z] = false;
                    else if (A[i][j][z]) return false;
                }
            }
        return true;
    }

    bool dfs(int x) {
        if (x == 6) return true;
        for (int k = 0; k < 6; k++)
            if (!used[k]) {
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j <= 1; j++) {
                        if (!gao(x, k, i, j, 0)) continue;
                        gao(x, k, i, j, 1);
                        used[k] = true;
                        if (dfs(x + 1)) return true;
                        used[k] = false;
                        gao(x, k, i, j, -1);
                    }
            }
        return false;
    }

public:
    bool composeCube(vector<vector<string>> &shapes) {
        n = (int) shapes[0].size();
        int expected = n * n * n - (n - 2) * (n - 2) * (n - 2);
        int actual = 0;
        for (auto &shape: shapes) for (auto &line: shape) for (char c: line) actual += c - '0';
        if (expected != actual) return false;
        this->shapes = shapes;
        return dfs(0);
    }
};