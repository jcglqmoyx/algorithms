#include <bits/stdc++.h>

using namespace std;

class Solution {
    int is_subsequence(string &a, string &b) {
        int m = (int) a.size(), n = (int) b.size();
        if (m > n) return false;
        int i = 0;
        for (int j = 0; i < m && j < n;) {
            while (j < n && a[i] != b[j]) j++;
            if (j == n) return false;
            i++;
            j++;
        }
        return i == m;
    }

public:
    int findLUSlength(vector<string> &strs) {
        int n = (int) strs.size();
        int res = -1;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i != j && is_subsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res = max(res, (int) strs[i].length());
            }
        }
        return res;
    }
};