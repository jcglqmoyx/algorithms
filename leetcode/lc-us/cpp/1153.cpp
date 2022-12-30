#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        int n = (int) str1.size();
        int map[26];
        memset(map, -1, sizeof map);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char a = str1[i], b = str2[i];
            if (map[a - 'a'] != -1) {
                if (map[a - 'a'] != b) return false;
            } else {
                map[a - 'a'] = (unsigned char) b;
            }
            cnt |= 1 << (b - 'a');
        }
        for (int i = 0; i < 26; i++) {
            if (!(cnt >> i & 1)) return true;
        }
        return false;
    }
};