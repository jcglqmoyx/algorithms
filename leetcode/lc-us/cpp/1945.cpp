#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for (char c: s) {
            int num = c - 'a' + 1;
            str += to_string(num);
        }
        int res = 0;
        for (char c: str) res += c - '0';
        for (int i = 0; i < k - 1; i++) {
            int tmp = res;
            int sum = 0;
            while (tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            res = sum;
        }
        return res;
    }
};