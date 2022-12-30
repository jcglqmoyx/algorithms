#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
        int n = (int) aliceValues.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]};
        sort(v.begin(), v.end(), greater<>());
        int res = 0;
        for (int i = 0, j = 0; i < n; i++, j++) {
            if (j & 1) res -= v[i][2];
            else res += v[i][1];
        }
        if (res > 0) return 1;
        else if (res < 0) return -1;
        else return 0;
    }
};