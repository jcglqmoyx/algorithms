#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
        size_t r1 = mat1.size(), c1 = mat1[0].size(), c2 = mat2[0].size();
        vector<vector<int>> res(r1, vector<int>(c2));
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                int sum = 0;
                for (int k = 0; k < c1; k++) {
                    sum += mat1[i][k] * mat2[k][j];
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};