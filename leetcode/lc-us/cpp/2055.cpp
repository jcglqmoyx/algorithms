#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        int n = (int) s.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i - 1] == '*');
        vector<int> l(n), r(n);
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == '|') j = i;
            l[i] = j;
        }
        for (int i = n - 1, j = n; ~i; i--) {
            if (s[i] == '|') j = i;
            r[i] = j;
        }
        n = (int) queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int start = queries[i][0], end = queries[i][1];
            res[i] = max(sum[l[end] + 1] - sum[r[start]], 0);
        }
        return res;
    }
};