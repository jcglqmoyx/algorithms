#include <bits/stdc++.h>

using namespace std;

class Solution {
    static int get(string &s, char c) {
        int n = (int) s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                int j = i;
                while (j < n && s[j] == c) j++;
                res += max(0, j - i - 2);
                i = j - 1;
            }
        }
        return res;
    }

public:
    bool winnerOfGame(string colors) {
        int a = get(colors, 'A'), b = get(colors, 'B');
        return a > b;
    }
};