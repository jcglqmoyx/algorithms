#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int n = (int) strs.size(), m = (int) strs[0].size(), res = 0;
        vector<bool> f(n);
        for (int j = 0; j < m; j++) {
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (!f[i] && strs[i][j] < strs[i - 1][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                res++;
            } else {
                for (int i = 1; i < n; i++) {
                    if (!f[i] && strs[i][j] > strs[i - 1][j]) {
                        f[i] = true;
                    }
                }
            }
        }
        return res;
    }
};