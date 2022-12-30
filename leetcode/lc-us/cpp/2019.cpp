#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scoreOfStudents(string s, vector<int> &answers) {
        int cnt[1001] = {};
        for (int x: answers) cnt[x]++;
        int ans = 0;
        int n = (int) s.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) stk.push(s[i] - '0');
            else if (s[i] == '*') stk.top() *= s[i + 1] - '0', i++;
        }
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        int res = cnt[ans] * 5;
        unordered_set<int> f[n][n];
        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i += 2) {
                int j = i + len - 1;
                if (len == 1) {
                    f[i][j].insert(s[i] - '0');
                } else {
                    for (int k = i + 1; k < j; k += 2) {
                        int t;
                        for (int x: f[i][k - 1]) {
                            for (int y: f[k + 1][j]) {
                                if (s[k] == '+') t = x + y;
                                else t = x * y;
                                if (t >= 0 && t <= 1000) {
                                    f[i][j].insert(t);
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int x: f[0][n - 1]) {
            if (x != ans) res += cnt[x] * 2;
        }
        return res;
    }
};