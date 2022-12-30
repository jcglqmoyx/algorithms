#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
        char cur = 'a';
        for (char c: word) {
            res++;
            if (c == cur) continue;
            int tmp = min(abs(c - cur), abs('z' - cur + c - 'a' + 1));
            tmp = min(tmp, abs('z' - c + cur - 'a' + 1));
            res += tmp;
            cur = c;
        }
        return res;
    }
};