#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = (int) s.size();
        string res;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j <= n; j++) {
                string str = s.substr(i, j - i + 1);
                if (is_nice(str) && str.size() > res.size()) {
                    res = str;
                }
            }
        }
        return res;
    }

private:
    static bool is_nice(string &str) {
        int cnt1[26] = {}, cnt2[26] = {};
        for (char c: str) {
            if (isupper(c)) cnt1[c - 'A']++;
            else cnt2[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (!cnt1[i] && cnt2[i] || cnt1[i] && !cnt2[i]) {
                return false;
            }
        }
        return true;
    }
};