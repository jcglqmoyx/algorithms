#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0;
        char a = pattern[0], b = pattern[1];
        if (a == b) {
            long long cnt = 1;
            for (char c: text) {
                if (c == a) cnt++;
            }
            return cnt * (cnt - 1) >> 1;
        }
        int x = 0, y = 0;
        for (char c: text) {
            if (c == a) x++;
            else if (c == b) res += x, y++;
        }
        return res + max(x, y);
    }
};