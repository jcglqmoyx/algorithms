#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSumScore(vector<int> &nums) {
        using LL = long long;
        LL res = INT64_MIN, left = 0, right = 0;
        for (int x: nums) right += x;
        for (int num: nums) {
            left += num;
            res = max(res, max(left, right));
            right -= num;
        }
        return res;
    }
};