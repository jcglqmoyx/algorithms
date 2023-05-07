#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int> &cost) {
        long long ans = 0;
        function<long long(int)> f = [&](int x) {
            int L = x * 2, R = x * 2 + 1;
            if (L > n) return 1LL * cost[x - 1];
            long long a = f(L), b = f(R);
            ans += max(a, b) - min(a, b);
            return max(a, b) + cost[x - 1];
        };
        f(1);
        return (int) ans;
    }
};