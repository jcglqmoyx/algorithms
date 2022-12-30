#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int m) {
        int n = (int) piles.size();
        vector<int> f(m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = m; j; j--) {
                for (int k = 0, sum = 0; k < piles[i].size(); k++) {
                    sum += piles[i][k];
                    if (k + 1 <= j) f[j] = max(f[j], f[j - k - 1] + sum);
                }
            }
        }
        return f[m];
    }
};