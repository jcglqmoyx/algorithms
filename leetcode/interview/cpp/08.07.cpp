#include <bits/stdc++.h>

using namespace std;

class Solution {
    string path;
    vector<string> result;
    vector<bool> used;

    void backtracking(string s) {
        if (path.size() == s.size()) {
            result.emplace_back(path);
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) {
                continue;
            }
            if (!used[i]) {
                used[i] = true;
                path.push_back(s[i]);
                backtracking(s);
                used[i] = false;
                path.pop_back();
            }
        }
    }

public:
    vector<string> permutation(string S) {
        int n = (int) S.size();
        used.resize(n, false);
        sort(S.begin(), S.end());
        backtracking(S);
        return result;
    }
};