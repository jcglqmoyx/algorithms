#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>> &mappings) {
        int n = (int) s.size(), m = (int) sub.size();
        unordered_map<char, unordered_set<int>> M;
        for (auto &e: mappings) {
            M[e[0]].insert(e[1]);
        }
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int p = i, q = 0; q < m; p++, q++) {
                if (s[p] != sub[q] && !M[sub[q]].count(s[p])) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};