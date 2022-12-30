#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = (int) s.size();
        int zero = 0;
        for (int i = 0; i < n; i++) if (s[i] == '0') zero++;
        int one = n - zero;
        int left_one[100005] = {}, right_zero[100005] = {};
        for (int i = 1; i <= n; i++) {
            left_one[i] = left_one[i - 1];
            if (s[i - 1] == '1') left_one[i]++;
        }
        for (int i = n; i >= 1; i--) {
            right_zero[i] = right_zero[i + 1];
            if (s[i - 1] == '0') right_zero[i]++;
        }
        int res = min(zero, one);
        for (int i = 1; i <= n; i++) {
            res = min(res, left_one[i] + right_zero[i + 1]);
        }
        return res;
    }
};