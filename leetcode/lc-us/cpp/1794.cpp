#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        int l[123], r[123];
        memset(l, -1, sizeof l), memset(r, -1, sizeof r);

        int cnt_char = 0;
        for (int i = 0; i < (int) firstString.size(); i++) {
            char c = firstString[i];
            if (l[c] == -1) l[c] = i, cnt_char++;
            if (cnt_char == 26) break;
        }
        cnt_char = 0;
        for (int i = (int) secondString.size() - 1; ~i; i--) {
            char c = secondString[i];
            if (r[c] == -1) r[c] = i, cnt_char++;
            if (cnt_char == 26) break;
        }
        int mn = 1e6;
        for (char c = 'a'; c <= 'z'; c++) {
            if (l[c] != -1 && r[c] != -1) mn = min(mn, l[c] - r[c]);
        }
        if (mn > 1e6) return 0;
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (l[c] != -1 && r[c] != -1 && l[c] - r[c] == mn) cnt++;
        }
        return cnt;
    }
};