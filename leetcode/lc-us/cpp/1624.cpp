#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int map[26];
        memset(map, -1, sizeof map);
        int max_len = -1;
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i] - 'a'] >= 0) {
                max_len = max(max_len, i - map[s[i] - 'a'] - 1);
            } else {
                map[s[i] - 'a'] = i;
            }
        }
        return max_len;
    }
};