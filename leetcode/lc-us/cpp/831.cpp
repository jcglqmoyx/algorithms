#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        int n = (int) s.size();
        bool is_email = false;
        for (char c: s) {
            if (c == '@') {
                is_email = true;
                break;
            }
        }
        string res;
        if (is_email) {
            res.push_back(tolower(s.front()));
            res += "*****";
            for (int i = 0; i < n; i++) {
                if (s[i] != '@') continue;
                res.push_back(tolower(s[i - 1]));
                for (int j = i; j < n; j++) {
                    if (isalpha(s[j])) res.push_back(tolower(s[j]));
                    else res.push_back(s[j]);
                }
                break;
            }
        } else {
            int cnt = 0;
            string t;
            for (int i = 0; i < n; i++) {
                if (isdigit(s[i])) cnt++, t.push_back(s[i]);
            }
            if (cnt == 10) return "***-***-" + t.substr(6, 4);
            res = "+";
            for (int i = 0; i < t.size() - 10; i++) res.push_back('*');
            res += "-***-***-";
            res += t.substr(t.size() - 4, 4);
        }
        return res;
    }
};