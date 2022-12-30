#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        using LL = long long;

        if (num == 0) return num;
        if (num < 0) {
            num = -num;
            vector<int> d;
            while (num) {
                d.push_back((int) (num % 10));
                num /= 10;
            }
            sort(d.begin(), d.end(), greater<>());
            LL res = 0;
            for (int x: d) {
                res = res * 10 + x;
            }
            return -res;
        } else {
            vector<int> d;
            while (num) {
                d.push_back((int) (num % 10));
                num /= 10;
            }
            sort(d.begin(), d.end());
            LL res;
            int digit = 0;
            for (int x: d) {
                if (x) {
                    digit = x;
                    break;
                }
            }
            int cnt0 = 0;
            for (int x: d) {
                if (x == 0) cnt0++;
            }
            res = digit;
            bool flag = true;
            for (int x: d) {
                if (x == digit && flag) {
                    flag = false;
                    continue;
                }
                res = res * 10 + x;
            }
            return res;
        }
    }
};