#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    int res = 0;

    static bool check(string &s) {
        int l = 0, r = (int) s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    void dfs(string &s, string &a, string &b, int idx) {
        if (idx == n) {
            if (check(a) && check(b)) res = max(res, (int) a.size() * (int) b.size());
            return;
        }
        a.push_back(s[idx]);
        dfs(s, a, b, idx + 1);
        a.pop_back();
        b.push_back(s[idx]);
        dfs(s, a, b, idx + 1);
        b.pop_back();
        dfs(s, a, b, idx + 1);
    }

public:
    int maxProduct(string s) {
        n = (int) s.size();
        string a, b;
        dfs(s, a, b, 0);
        return res;
    }
};
