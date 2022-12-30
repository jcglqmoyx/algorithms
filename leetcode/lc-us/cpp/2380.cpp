#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res = 0, cnt = 0;
        for (char c: s) {
            if (c == '0') cnt++;
            else if (cnt) res = max(res + 1, cnt);
        }
        return res;
    }
};