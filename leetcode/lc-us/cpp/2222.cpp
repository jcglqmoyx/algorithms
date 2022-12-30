#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        using LL = long long;
        int n = (int) s.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i - 1] == '1');
        LL res = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                res += (LL) pre[i - 1] * (pre[n] - pre[i]);
            } else {
                res += (LL) (i - 1 - (pre[i - 1])) * (n - i - (pre[n] - pre[i]));
            }
        }
        return res;
    }
};