#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        long long res = 0;
        unordered_map<long long, int> cnt;
        cnt[0] = 1;
        int cnt0 = 0, cnt1 = 0;
        for (char c: s) {
            if (c == '0') cnt0++;
            else cnt1++;
            long long t = (long long) cnt0 * num2 - (long long) cnt1 * num1;
            res += cnt[t];
            cnt[t]++;
        }
        return res;
    }
};