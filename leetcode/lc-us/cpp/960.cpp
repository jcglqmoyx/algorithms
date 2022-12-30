#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(vector<string> &strs, int col1, int col2) {
        for (auto &str: strs) {
            if (str[col1] > str[col2]) {
                return false;
            }
        }
        return true;
    }

public:
    int minDeletionSize(vector<string> &strs) {
        int n = (int) strs.size(), m = (int) strs[0].size();
        vector<int> f(m);
        for (int i = 0; i < m; i++) {
            f[i] = i;
            for (int j = 0; j < i; j++) {
                if (check(strs, j, i)) {
                    f[i] = min(f[i], f[j] + i - j - 1);
                }
            }
        }
        int res = m;
        for (int i = 0; i < m; i++) {
            res = min(res, f[i] + m - i - 1);
        }
        return res;
    }
};