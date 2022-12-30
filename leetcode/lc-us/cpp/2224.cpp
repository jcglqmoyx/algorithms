#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(string s) {
        int h, m;
        sscanf(s.c_str(), "%d:%d", &h, &m);
        return h * 60 + m;
    }

public:
    int convertTime(string current, string correct) {
        int start = get(move(current)), end = get(move(correct));
        int res = 0;
        int op[4] = {60, 15, 5, 1};
        for (int i = 0; i < 4 && end > start; i++) {
            int diff = end - start;
            int t = diff / op[i];
            res += t;
            end -= t * op[i];
        }
        return res;
    }
};