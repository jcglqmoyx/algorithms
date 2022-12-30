#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd, even;
        vector<int> digits;
        while (num) {
            int d = num % 10;
            digits.push_back(d);
            if (d & 1) odd.push_back(d);
            else even.push_back(d);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end(), greater<>());
        int i = 0, j = 0;
        int res = 0;
        for (int digit: digits) {
            if (digit & 1) {
                res = res * 10 + odd[i++];
            } else {
                res = res * 10 + even[j++];
            }
        }
        return res;
    }
};