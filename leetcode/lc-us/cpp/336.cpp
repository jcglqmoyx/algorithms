#include <bits/stdc++.h>

using namespace std;

class Solution {
    inline bool is_palindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++, end--;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = (int) words.size();
        vector<vector<int>> res;
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++) {
            string t = words[i];
            reverse(t.begin(), t.end());
            map[t] = i;
        }
        for (int i = 0; i < n; i++) {
            string s = words[i];
            int m = (int) s.size();
            if (!m) continue;
            for (int j = 0; j <= m; j++) {
                if (!is_palindrome(s, 0, j - 1)) continue;
                string t = s.substr(j);
                auto it = map.find(t);
                if (it == map.end()) continue;
                if (i != it->second) {
                    res.push_back({it->second, i});
                }
            }
            for (int j = m - 1; j >= 0; j--) {
                if (!is_palindrome(s, j, m - 1)) continue;
                string t = s.substr(0, j);
                auto it = map.find(t);
                if (it == map.end()) continue;
                if (i != it->second) {
                    res.push_back({i, it->second});
                }
            }
        }
        return res;
    }
};