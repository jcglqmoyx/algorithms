#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = (int) nums.size();
        int expected_sum = n * (n + 1) / 2;
        int sum = 0;
        for (int num: nums) sum += num;
        return expected_sum - sum;
    }
};