#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> map;
        int n = (int) s.size();
        int res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            map[s[j]]++;
            if (map.size() > 2) {
                while (map.size() > 2) {
                    if (map.find(s[i]) != map.end()) {
                        if (map[s[i]] == 1) {
                            map.erase(s[i]);
                        } else {
                            map[s[i]]--;
                        }
                        i++;
                    }
                }
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};