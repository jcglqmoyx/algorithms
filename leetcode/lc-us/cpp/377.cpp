#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<long long> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num: nums) {
                if (i >= num) f[i] = (f[i] + f[i - num]) % INT32_MAX;
            }
        }
        return (int) f[target];
    }
};