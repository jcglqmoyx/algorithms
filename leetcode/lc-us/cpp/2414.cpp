#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = (int) s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && s[j] - s[j - 1] == 1) j++;
            res = max(res, j - i);
            i = j - 1;
        }
        return res;
    }
};