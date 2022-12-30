#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        using LL = long long;
        int last[26], n = (int) s.size();
        memset(last, -1, sizeof last);
        LL res = 0;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            res += (LL) (i - last[idx]) * (n - i);
            last[idx] = i;
        }
        return res;
    }
};