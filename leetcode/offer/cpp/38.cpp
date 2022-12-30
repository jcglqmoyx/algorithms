#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> res;
    string str;
    vector<bool> used;

    void dfs(string &s, int index) {
        if (index == s.length()) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < s.length(); i++) {
            if (used[i] || i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
            str.push_back(s[i]);
            used[i] = true;
            dfs(s, index + 1);
            str.pop_back();
            used[i] = false;
        }
    }

public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        used.resize(s.length());
        dfs(s, 0);
        return res;
    }
};