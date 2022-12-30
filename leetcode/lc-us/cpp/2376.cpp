#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> digits;
        while (n) digits.push_back(n % 10), n /= 10;
        reverse(digits.begin(), digits.end());
        int res = 0;
        for (int len = 1; len < digits.size(); len++) {
            int t = 9;
            for (int i = 9, j = 1; j < len; i--, j++) {
                t *= i;
            }
            res += t;
        }
        bool st[10] = {};
        for (int i = 0; i < digits.size(); i++) {
            for (int j = !i; j < digits[i]; j++) {
                if (st[j]) continue;
                int t = 1;
                for (int k = i + 1; k < digits.size(); k++) {
                    t *= 10 - k;
                }
                res += t;
            }
            if (st[digits[i]]) break;
            st[digits[i]] = true;
        }
        unordered_set<int> S(digits.begin(), digits.end());
        if (S.size() == digits.size()) res++;
        return res;
    }
};