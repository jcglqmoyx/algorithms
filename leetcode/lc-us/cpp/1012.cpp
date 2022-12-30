#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> digits;
        int m = n;
        while (n) digits.push_back(n % 10), n /= 10;
        int count = 0;
        for (int len = 1; len < digits.size(); len++) {
            int t = 9;
            for (int i = 9, j = 1; j < len; i--, j++) {
                t *= i;
            }
            count += t;
        }
        reverse(digits.begin(), digits.end());
        bool used[10] = {};
        for (int i = 0; i < digits.size(); i++) {
            for (int j = !i; j < digits[i]; j++) {
                if (used[j]) continue;
                int t = 1;
                for (int k = i + 1; k < digits.size(); k++) {
                    t *= 10 - k;
                }
                count += t;
            }
            if (used[digits[i]]) break;
            used[digits[i]] = true;
        }
        unordered_set<int> S;
        for (int digit: digits) S.insert(digit);
        if (S.size() == digits.size()) count++;
        return m - count;
    }
};