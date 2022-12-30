#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string nearestPalindromic(string s) {
        using LL = long long;
        int n = (int) s.size();
        LL num = stoll(s);
        if (num <= 10) return to_string(num - 1);
        else if (num == 11) return "9";
        else if (num <= 16) return "11";
        else {
            LL t = num;
            while (t % 10 == 0) t /= 10;
            if (t == 1) return to_string(num - 1);
        }
        string res;
        LL min_diff = LONG_LONG_MAX;
        for (int dt = -1; dt <= 1; dt++) {
            string left = s.substr(0, n / 2 + (n & 1));
            LL l = stoll(left) + dt;
            string right = to_string(l).substr(0, n / 2);
            reverse(right.begin(), right.end());
            LL new_num = l * (LL) pow(10, n / 2) + stoll(right);
            string a = to_string(l), b = right;
            LL diff = abs(num - new_num);
            if (diff < min_diff && a + b != s) {
                min_diff = diff;
                res = a + b;
            }
        }
        return res;
    }
};