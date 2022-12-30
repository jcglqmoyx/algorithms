#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        n = (int) nums.size(), res = 0;
        dfs(nums, 0, 0, target);
        return res;
    }

private:
    void dfs(vector<int> &nums, int index, int sum, int target) {
        if (index == n) {
            if (sum == target) {
                res++;
            }
            return;
        }
        sum += nums[index];
        dfs(nums, index + 1, sum, target);
        sum -= nums[index] * 2;
        dfs(nums, index + 1, sum, target);
    }

    int n, res;
};