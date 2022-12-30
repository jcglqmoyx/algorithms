#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            char c = s[j];
            if (set.count(c)) {
                while (set.count(c)) {
                    set.erase(s[i++]);
                }
            }
            set.insert(c);
            res = max(res, (int) set.size());
        }
        return res;
    }
};