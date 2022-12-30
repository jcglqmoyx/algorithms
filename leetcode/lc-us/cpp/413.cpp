#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = (int) nums.size();
        if (n < 3) return 0;
        int len;
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i - 2] - nums[i - 1] == nums[i - 1] - nums[i]) {
                int diff = nums[i - 1] - nums[i];
                int j = i + 1;
                while (j < n && nums[j - 1] - nums[j] == diff) {
                    j++;
                }
                len = j - i + 2;
                res += (len - 1) * (len - 2) / 2;
                i = j;
            }
        }
        return res;
    }
};