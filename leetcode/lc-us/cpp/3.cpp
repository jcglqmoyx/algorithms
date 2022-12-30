#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int res = 1, n = (int) s.size();
        unordered_set<char> set;
        for (int i = 0, j = 0; j < n; j++) {
            if (set.count(s[j])) {
                while (set.count(s[j])) {
                    set.erase(s[i++]);
                }
            }
            set.insert(s[j]);
            res = max(res, (int) set.size());
        }
        return res;
    }
};