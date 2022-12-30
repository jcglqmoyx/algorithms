#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        int i = 0, p = 0, j = 0;
        int cnt;
        while (j < chars.size()) {
            while (j < chars.size() && chars[j] == chars[p]) j++;
            cnt = j - p;
            chars[i] = chars[j - 1];
            if (cnt > 1) {
                string s = to_string(cnt);
                for (char c: s) {
                    chars[++i] = c;
                }
                i++;
            } else {
                i++;
            }
            p = j;
        }
        return i;
    }
};