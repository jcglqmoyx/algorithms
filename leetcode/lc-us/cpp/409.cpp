#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {};
        for (char c: s) {
            count[c]++;
        }
        int res = 0;
        bool has_odd_count = false;
        for (int num: count) {
            if (num % 2 == 0) {
                res += num;
            } else {
                res += num - 1;
                has_odd_count = true;
            }
        }
        return has_odd_count ? res + 1 : res;
    }
};