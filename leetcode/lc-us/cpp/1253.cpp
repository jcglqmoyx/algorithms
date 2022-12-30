#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum) {
        vector<vector<int>> res;
        int n = (int) colsum.size(), sum = accumulate(colsum.begin(), colsum.end(), 0);
        if (sum != upper + lower || upper > n || lower > n) return res;
        res.resize(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 0) res[0][i] = res[1][i] = 0;
            else if (colsum[i] == 2) res[0][i] = res[1][i] = 1, upper--, lower--;
            else {
                if (upper > lower) res[0][i] = 1, res[1][i] = 0, upper--;
                else res[0][i] = 0, res[1][i] = 1, lower--;
            }
            if (upper < 0 || lower < 0) {
                res = {};
                break;
            }
        }
        return res;
    }
};