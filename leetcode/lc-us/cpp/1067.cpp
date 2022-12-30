#include <bits/stdc++.h>

using namespace std;

class Solution {
    static int count(int n, int d) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        int res = 0;
        for (int i = 0; i < digits.size(); i++) {
            int left = 0, right = 0, p = (int) pow(10, digits.size() - 1 - i);
            for (int j = 0; j < i; j++) left = left * 10 + digits[j];
            for (int j = i + 1; j < digits.size(); j++) right = right * 10 + digits[j];
            if (!d) {
                if (!i) {
                    continue;
                } else {
                    if (!digits[i]) res += (left - 1) * p + right + 1;
                    else res += left * p;
                }
            } else {
                if (digits[i] > d) res += (left + 1) * p;
                else if (digits[i] == d) res += left * p + right + 1;
                else res += left * p;
            }
        }
        return res;
    }

public:
    int digitsCount(int d, int low, int high) {
        return count(high, d) - count(low - 1, d);
    }
};