#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int> &nums) {
        long long res = 0;
        for (int i = (int) nums.size() - 2; ~i; i--) {
            if (nums[i + 1] < nums[i]) {
                int t = (nums[i] + nums[i + 1] - 1) / nums[i + 1] - 1;
                res += t;
                if (nums[i] % nums[i + 1] == 0) nums[i] = nums[i + 1];
                else nums[i] = nums[i] / (t + 1);
            }
        }
        return res;
    }
};