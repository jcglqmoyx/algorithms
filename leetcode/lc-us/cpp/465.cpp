#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>> &transactions) {
        unordered_map<int, int> map;
        for (auto &t: transactions) {
            map[t[0]] -= t[2];
            map[t[1]] += t[2];
        }
        vector<int> v;
        for (auto[person, balance]: map) {
            if (balance) v.push_back(balance);
        }
        int n = (int) v.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < 1 << n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    sum[i] = sum[i ^ (1 << j)] + v[j];
                    break;
                }
            }
        }
        vector<int> f(1 << n);
        for (int i = 1; i < 1 << n; i++) {
            if (sum[i]) continue;
            f[i] = 1;
            for (int st = i & (i - 1); st; st = (st - 1) & i) {
                if (f[st]) {
                    f[i] = max(f[i], f[st] + 1);
                }
            }
        }
        return n - f[(1 << n) - 1];
    }
};