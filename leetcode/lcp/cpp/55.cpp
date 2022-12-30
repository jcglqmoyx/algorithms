#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit) {
        int res = 0;
        for (auto &f: fruits) {
            int type = f[0], num = f[1];
            res += (num + limit - 1) / limit * time[type];
        }
        return res;
    }
};