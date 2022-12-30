#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        int n = (int) s.size();
        if (n <= k) return s;
        string res;
        for (int i = 0; i < n; i += k) {
            int sum = 0;
            for (int j = i; j < min(n, i + k); j++) {
                sum += s[j] - '0';
            }
            res += to_string(sum);
        }
        return digitSum(res, k);
    }
};