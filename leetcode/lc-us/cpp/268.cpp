#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int size = (int) nums.size();
        int sum = size * (size + 1) / 2;
        int real_sum = 0;
        for (int num: nums) {
            real_sum += num;
        }
        return sum - real_sum;
    }
};