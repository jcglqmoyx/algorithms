#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int> &nums, int k) {
        using LL = long long;

        LL res = 0;
        nums.push_back(0);
        nums.push_back(INT32_MAX);
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        for (int i = 0; i < n - 1 && k; i++) {
            int diff = nums[i + 1] - nums[i];
            if (diff > 1) {
                int cnt = min(diff - 1, k);
                LL t = (LL) (nums[i] + 1 + nums[i] + cnt) * cnt / 2;
                k -= cnt;
                res += t;
            }
        }
        return res;
    }
};