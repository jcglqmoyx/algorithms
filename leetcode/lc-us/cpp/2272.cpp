#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int res = 0, n = (int) s.size();
        for (char a = 'a'; a <= 'z'; a++) {
            for (char b = 'a'; b <= 'z'; b++) {
                if (a == b) continue;
                int diff = 0, diff_with_b = -n;
                for (char c: s) {
                    if (c == a) {
                        diff++;
                        diff_with_b++;
                    } else if (c == b) {
                        diff_with_b = --diff;
                        diff = max(diff, 0);
                    }
                    res = max(res, diff_with_b);
                }
            }
        }
        return res;
    }
};