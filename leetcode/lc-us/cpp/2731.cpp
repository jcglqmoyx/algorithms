#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumDistance(vector<int> &nums, string s, int d) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        int n = (int) nums.size();
        vector<LL> v(n);
        for (int i = 0; i < n; i++) v[i] = (LL) nums[i] + d * (s[i] == 'L' ? -1 : 1);
        sort(v.begin(), v.end());
        LL t = 0;
        for (int i = 1; i < n; i++) t += v[i] - v[0];
        LL res = t;
        for (int i = 1; i < n - 1; i++) {
            t -= (LL) (n - i) * (v[i] - v[i - 1]);
            res = (res + t) % MOD;
        }
        return (int) res;
    }
};