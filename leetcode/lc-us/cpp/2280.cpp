#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>> &stockPrices) {
        using LL = long long;
        sort(stockPrices.begin(), stockPrices.end());
        int cnt = 0;
        LL x = 1e9, y = 1e9;
        for (int i = 0; i + 1 < stockPrices.size(); i++) {
            LL dx = (LL) stockPrices[i][0] - stockPrices[i + 1][0];
            LL dy = (LL) stockPrices[i][1] - stockPrices[i + 1][1];
            if (cnt == 0 || dx * y != dy * x) cnt++, x = dx, y = dy;
        }
        return cnt;
    }
};