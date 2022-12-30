#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        str = s;
        dfs(0, 0);
        return paths;
    }

private:
    string str;
    vector<string> path;
    vector<vector<string>> paths;

    bool is_palindrome(int l, int r) {
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++, r--;
        }
        return true;
    }

    void dfs(int last, int cur) {
        if (cur == str.size()) {
            if (is_palindrome(last, cur - 1)) {
                paths.push_back(path);
            }
            return;
        }
        for (int i = cur; i < str.size(); i++) {
            if (is_palindrome(last, i)) {
                path.push_back(str.substr(last, i - last + 1));
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        }
    }
};