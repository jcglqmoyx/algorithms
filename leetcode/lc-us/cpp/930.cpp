#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int res = 0;
        int n = (int) nums.size();
        if (goal == 0) {
            int len = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    len++;
                    if (i == n - 1) {
                        res += (len + 1) * len / 2;
                    }
                } else {
                    res += (len + 1) * len / 2;
                    len = 0;
                }
            }
        } else {
            unordered_map<int, int> cnt;
            int prev = 0, sum;
            cnt[0] = 1;
            for (int num: nums) {
                sum = prev + num;
                prev = sum;
                cnt[sum]++;
                res += cnt[sum - goal];
            }
        }
        return res;
    }
};