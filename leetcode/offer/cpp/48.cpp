#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size();
        unordered_set<char> set;
        for (int i = 0, j = 0; j < n; j++) {
            while (set.count(s[j])) {
                set.erase(s[i++]);
            }
            set.insert(s[j]);
            res = max(res, j - i + 1);
        }
        return res;
    }
};