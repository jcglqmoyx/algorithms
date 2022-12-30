#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = (int) s.size();
        vector<int> l(n), r(n);
        vector<int> p(26, -1);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'A';
            l[i] = p[idx];
            p[idx] = i;
        }
        p = vector<int>(26, n);
        for (int i = n - 1; ~i; i--) {
            int idx = s[i] - 'A';
            r[i] = p[idx];
            p[idx] = i;
        }
        int res = 0, MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            res = (int) ((res + (long long) (i - l[i]) * (r[i] - i)) % MOD);
        }
        return res;
    }
};