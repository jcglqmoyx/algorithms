#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int res = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            map[s[j]]++;
            while (map.size() > k) {
                map[s[i]]--;
                if (map[s[i]] == 0) map.erase(s[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};