#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int cnt_zero = 0, cnt_one = 0;
        for (char c: s) {
            if (c == '0') cnt_zero++;
            else cnt_one++;
        }
        if (abs(cnt_zero - cnt_one) > 1) return -1;
        int n = (int) s.size();
        if (cnt_zero > cnt_one) {
            string s1;
            int p = 0;
            for (int i = 0; i < n; i++) {
                if (i & 1) s1.push_back('1');
                else s1.push_back('0');
            }
            for (int i = 0; i < n; i++) {
                if (s[i] != s1[i]) {
                    p++;
                }
            }
            return p / 2;
        } else if (cnt_zero < cnt_one) {
            string s2;
            for (int i = 0; i < n; i++) {
                if (i & 1) s2.push_back('0');
                else s2.push_back('1');
            }
            int p = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != s2[i]) {
                    p++;
                }
            }
            return p / 2;
        } else {
            string s1, s2;
            for (int i = 0; i < n; i++) {
                if (i & 1) s1.push_back('1');
                else s1.push_back('0');
            }
            for (int i = 0; i < n; i++) {
                if (i & 1) s2.push_back('0');
                else s2.push_back('1');
            }
            int p = 0, q = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != s1[i]) {
                    p++;
                }
                if (s[i] != s2[i]) {
                    q++;
                }
            }
            return min(p, q) / 2;
        }
    }
};