#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        _s = s, n = (int) s.size();
        int left = 0, to_delete = 0;
        for (char c: s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left) left--;
                else to_delete++;
            }
        }
        n -= to_delete + left;
        if (!n) return {""};
        dfs(0, 0, 0);
        vector<string> res = vector<string>(set.begin(), set.end());
        return res;
    }

private:
    int n;
    string cur, _s;
    unordered_set<string> set;

    void dfs(int u, int left, int right) {
        if (cur.size() > n) return;
        if (u == _s.size()) {
            if (cur.size() == n && left == right) set.insert(cur);
            return;
        }
        char c = _s[u];
        if (c == '(') {
            cur.push_back(c);
            dfs(u + 1, left + 1, right);
            cur.pop_back();
            dfs(u + 1, left, right);
        } else if (c == ')' && left > right) {
            cur.push_back(c);
            dfs(u + 1, left, right + 1);
            cur.pop_back();
            dfs(u + 1, left, right);
        } else if (isalpha(c)) {
            cur.push_back(c);
            dfs(u + 1, left, right);
            cur.pop_back();
        } else {
            dfs(u + 1, left, right);
        }
    }
};