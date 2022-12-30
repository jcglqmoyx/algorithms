#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(vector<int> &houses, int k) {
        sort(houses.begin(), houses.end());
        int n = (int) houses.size();
        int f[k + 1][n];
        memset(f, -1, sizeof f);
        auto get = [&](int start, int end) {
            int mid = (start + end) >> 1;
            int res = 0;
            for (int i = start; i <= end; i++) {
                res += abs(houses[i] - houses[mid]);
            }
            return res;
        };
        function<int(int, int)> dp = [&](int u, int i) -> int {
            int &v = f[u][i];
            if (v != -1) return v;
            if (u == 1) {
                v = get(0, i);
            } else {
                v = 1e9;
                for (int j = i; j; j--) {
                    v = min(v, dp(u - 1, j - 1) + get(j, i));
                }
            }
            return v;
        };
        return dp(k, n - 1);
    }
};