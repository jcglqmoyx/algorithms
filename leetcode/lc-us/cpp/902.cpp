#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        int m = (int) digits.size();
        int p[10] = {1};
        string num = to_string(n);
        for (int i = 1; i < num.size(); i++) p[i] = p[i - 1] * m;
        int res = 0;
        m = (int) num.size();
        for (int i = 0; i < m; i++) {
            int x = num[i] - '0';
            int cnt = 0;
            bool flag = false;
            for (auto &digit: digits) {
                int t = digit[0] - '0';
                if (t < x) cnt++;
                else if (t == x) flag = true;
                else break;
            }
            res += cnt * p[m - i - 1];
            if (i < m - 1) res += p[m - i - 1];
            if (!flag) {
                for (int j = 1; j < m - i - 1; j++) res += p[j];
                break;
            }
            if (i + 1 == num.size()) res++;
        }
        return res;
    }
};