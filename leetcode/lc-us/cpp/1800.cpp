#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int> &nums) {
        int max_sum = 0;
        int sum = 0;
        int prev = 0;
        for (int num: nums) {
            if (num > prev) {
                sum += num;
            } else {
                sum = num;
            }
            prev = num;
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};