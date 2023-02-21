#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>> &lcp) {
        int n = (int) lcp.size();
        string s(n, 0);
        int i = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            while (i < n && s[i]) i++;
            if (i == n) break;
            for (int j = i; j < n; j++) {
                if (lcp[i][j]) s[j] = c;
            }
        }
        while (i < n) if (s[i++] == 0) return "";
        for (i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int f = s[i] == s[j] ? i == n - 1 || j == n - 1 ? 1 : lcp[i + 1][j + 1] + 1 : 0;
                if (lcp[i][j] != f) return "";
            }
        }
        return s;
    }
};