#include <bits/stdc++.h>

using namespace std;

class Solution {
    static int calc(string &s, char first, char second, int score) {
        int res = 0;
        string str;
        for (char c: s) {
            if (!str.empty() && str.back() == first && c == second) {
                res += score;
                str.pop_back();
                continue;
            }
            str.push_back(c);
        }
        s = str;
        return res;
    }

public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (char &c: s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }
        int res = 0;
        res += calc(s, 'a', 'b', x);
        res += calc(s, 'b', 'a', y);
        return res;
    }
};