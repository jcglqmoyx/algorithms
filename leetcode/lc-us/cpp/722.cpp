#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> res;
        bool is_comment = false;
        string cur;
        for (string &s: source) {
            int n = (int) s.size();
            int i = 0;
            if (!is_comment) cur.clear();
            while (i < n) {
                if (!is_comment && s.substr(i, 2) == "//") break;
                else if (!is_comment && s.substr(i, 2) == "/*") is_comment = true, i++;
                else if (is_comment && s.substr(i, 2) == "*/") is_comment = false, i++;
                else if (!is_comment) cur.push_back(s[i]);
                i++;
            }
            if (!is_comment && !cur.empty()) res.push_back(cur);
        }
        return res;
    }
};