#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        bool st[1001]{};
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) {
                res++;
                return;
            }
            dfs(i + 1);
            if (nums[i] - k <= 0 || !st[nums[i] - k]) {
                st[nums[i]] = true;
                dfs(i + 1);
                st[nums[i]] = false;
            }
        };
        dfs(0);
        return res - 1;
    }
};