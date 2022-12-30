#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        n = (int) ratings.size(), w = ratings;
        f.resize(n, -1);
        int res = 0;
        for (int i = 0; i < n; i++) res += dp(i);
        return res;
    }

private:
    int n;
    vector<int> f;
    vector<int> w;

    int dp(int u) {
        if (f[u] != -1) return f[u];
        f[u] = 1;
        if (u && w[u] > w[u - 1]) f[u] = max(f[u], dp(u - 1) + 1);
        if (u < n - 1 && w[u] > w[u + 1]) f[u] = max(f[u], dp(u + 1) + 1);
        return f[u];
    }
};