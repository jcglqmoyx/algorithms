#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOf2sInRange(int n) {
        vector<int> digits;
        while (n) digits.push_back(n % 10), n /= 10;
        int high = (int) digits.size() - 1;
        int res = 0;
        for (int i = high; i >= 0; i--) {
            int left = 0, right = 0, t = 1;
            for (int j = high; j > i; j--) left = left * 10 + digits[j];
            for (int j = i - 1; j >= 0; j--) right = right * 10 + digits[j], t *= 10;
            res += left * t;
            if (digits[i] > 2) res += t;
            else if (digits[i] == 2) res += right + 1;
        }
        return res;
    }
};