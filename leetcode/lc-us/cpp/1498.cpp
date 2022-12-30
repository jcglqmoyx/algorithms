#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int> &nums, int target) {
        const int MOD = 1e9 + 7;
        int n = (int) nums.size();
        int f[100010] = {1};
        for (int i = 1; i <= n; i++) {
            f[i] = (f[i - 1] * 2 % MOD);
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0, j = n - 1; i < n; i++) {
            while (j >= i && nums[j] + nums[i] > target) j--;
            if (j >= i) ans = (ans + f[j - i]) % MOD;
            else break;
        }
        return ans;
    }
};