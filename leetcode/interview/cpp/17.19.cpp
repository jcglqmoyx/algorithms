#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int> &nums) {
        int n = (int) nums.size() + 2;
        int sum = 0;
        for (int num: nums) sum += num;
        int expected_sum = (n + 1) * n / 2;
        int diff = expected_sum - sum;
        int half_diff = diff / 2;
        sum = 0;
        for (int num: nums) if (num <= half_diff) sum += num;
        int first = half_diff * (half_diff + 1) / 2 - sum;
        return {first, diff - first};
    }
};