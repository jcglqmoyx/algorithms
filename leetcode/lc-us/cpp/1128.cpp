#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        int res = 0;
        int count[10][10];
        memset(count, 0, sizeof count);
        for (vector<int> domino: dominoes) {
            count[domino[0]][domino[1]]++;
        }
        for (int i = 1; i <= 9; i++) {
            for (int j = i; j <= 9; j++) {
                int total = count[i][j];
                if (i != j) {
                    total += count[j][i];
                }
                res += total * (total - 1) / 2;
            }
        }
        return res;
    }
};