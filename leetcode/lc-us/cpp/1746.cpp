#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumAfterOperation(vector<int> &nums) {
        int res = 0;
        int a = 0, b = 0;
        for (int x: nums) {
            a = max(a + x, b + x * x);
            b = max(b + x, 0);
            res = max(res, a);
        }
        return res;
    }
};