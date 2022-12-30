#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool check(string &s, vector<vector<int>> &pre, int start, int end) {
        int cnt = 0;
        for (int d = 0; d <= 9; d++) {
            int t = pre[end][d] - pre[start - 1][d];
            if (t) {
                if (cnt && cnt != t) return false;
                else if (!cnt) cnt = t;
            }
        }
        return true;
    }

public:
    int equalDigitFrequency(string s) {
        using ULL = unsigned long long;
        const int P = 131;

        int n = (int) s.size();
        vector<ULL> p(n + 1), h(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
        }
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s[i - 1];
        }
        unordered_set<ULL> S;
        vector<vector<int>> pre(n + 1, vector<int>(10));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                pre[i][j] = pre[i - 1][j] + (s[i - 1] - '0' == j);
            }
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                if (check(s, pre, i, j)) S.insert(h[j] - h[i - 1] * p[len]);
            }
        }
        return (int) S.size();
    }
};