#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int size = (int) digits.size();
        int res = 0;
        for (int i = size - 1; i >= 0; i--) {
            int left = 0, right = 0, t = 1;
            for (int j = size - 1; j > i; j--) left = left * 10 + digits[j];
            for (int j = i - 1; ~j; j--) right = right * 10 + digits[j], t *= 10;
            res += left * t;
            if (digits[i] > 1) res += t;
            else if (digits[i] == 1) res += right + 1;
        }
        return res;
    }
};