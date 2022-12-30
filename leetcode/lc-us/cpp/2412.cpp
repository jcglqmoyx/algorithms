#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        using LL = long long;
        LL res = 0;
        LL sum = 0;
        for (auto &t: transactions) {
            if (t[0] > t[1]) {
                sum += t[0] - t[1];
            }
        }
        for (auto &t: transactions) {
            LL s = sum;
            if (t[0] > t[1]) s -= t[0] - t[1];
            res = max(res, s + t[0]);
        }
        return res;
    }
};