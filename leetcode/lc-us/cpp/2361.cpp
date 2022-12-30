#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> minimumCosts(vector<int> &regular, vector<int> &express, int expressCost) {
        using LL = long long;
        int n = (int) regular.size();
        LL a = 0, b = expressCost;
        vector<LL> res(n);
        for (int i = 0; i < n; i++) {
            LL x = min(a + regular[i], b + express[i]);
            LL y = min(a + regular[i] + expressCost, b + express[i]);
            a = x, b = y;
            res[i] = a;
        }
        return res;
    }
};