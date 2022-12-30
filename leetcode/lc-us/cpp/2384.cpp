#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {};
        int freq[10] = {};
        for (char c: num) cnt[c - '0']++;
        string res;
        for (int i = 9; ~i; i--) {
            if (cnt[i] > 1) {
                freq[i] = cnt[i] >> 1;
                cnt[i] -= freq[i] << 1;
            }
        }
        for (int i = 9; ~i; i--) {
            if (freq[i]) res += string(freq[i], i + '0');
        }
        for (int i = 9; ~i; i--) {
            if (cnt[i]) {
                res += string(cnt[i], i + '0');
                break;
            }
        }
        for (int i = 0; i <= 9; i++) {
            if (freq[i]) res += string(freq[i], i + '0');
        }
        int cnt0 = 0;
        for (char c: res) {
            if (c == '0') cnt0++;
            else break;
        }
        res = res.substr(cnt0, res.size() - cnt0 * 2);
        if (res.empty()) res = "0";
        return res;
    }
};