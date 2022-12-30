#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
        using LL = long long;
        int d[n], t[n];
        memset(d, 0, sizeof d);
        for (auto &r: roads) {
            d[r[0]]++, d[r[1]]++;
        }
        for (int i = 0; i < n; i++) t[i] = i;
        sort(t, t + n, [&](int i, int j) {
            return d[i] > d[j];
        });
        for (int value = n, i = 0; i < n; i++) {
            d[t[i]] = value--;
        }
        LL res = 0;
        for (auto &r: roads) {
            res += d[r[0]] + d[r[1]];
        }
        return res;
    }
};