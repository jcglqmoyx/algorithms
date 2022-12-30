#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> map = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && map[s[i]] < map[s[i + 1]]) {
                res -= map[s[i]];
            } else {
                res += map[s[i]];
            }
        }
        return res;
    }
};