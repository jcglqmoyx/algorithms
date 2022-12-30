#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int b1 = INT32_MIN, s1 = INT32_MIN, b2 = INT32_MIN, s2 = INT32_MIN, res = 0;
        for (int x: prices) {
            b1 = max(b1, -x);
            s1 = max(s1, x + b1);
            b2 = max(b2, s1 - x);
            s2 = max(s2, x + b2);
            res = max(res, max(s1, s2));
        }
        return res;
    }
};