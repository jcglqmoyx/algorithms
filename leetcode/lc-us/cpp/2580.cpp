#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>> &ranges) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        sort(ranges.begin(), ranges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int n = (int) ranges.size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back(ranges[i]);
            int j = i + 1;
            int end = ranges[i][1];
            while (j < n && ranges[j][0] <= end) {
                end = max(ranges[j][1], end);
                j++;
            }
            v.back().back() = end;
            i = j - 1;
        }
        LL res = 1;
        for (int i = 0; i < v.size(); i++) {
            res = res * 2 % MOD;
        }
        return res;
    }
};