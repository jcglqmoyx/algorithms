#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = (int) nums.size();
        int min_len = n;
        int sum = 0;
        int left = 0, right = 0;
        for (; right < nums.size(); right++) {
            sum += nums[right];
            if (sum >= target) {
                min_len = min(min_len, right - left + 1);
                while (sum - nums[left] >= target) {
                    sum -= nums[left++];
                    min_len = min(min_len, right - left + 1);
                }
            }
        }
        return sum >= target ? min_len : 0;
    }
};