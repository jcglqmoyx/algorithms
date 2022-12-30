#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string> cur;
    vector<vector<string>> res;

    void dfs(string &s, int start) {
        if (start == s.length()) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (!is_palindrome(s, start, i)) continue;
            cur.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            cur.pop_back();
        }
    }

    bool is_palindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};