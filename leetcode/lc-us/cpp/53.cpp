#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_sum = INT32_MIN, sum = 0;
        for (int num : nums) {
            if (sum > 0) sum += num;
            else sum = num;
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};