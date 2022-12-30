#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1000000007;

    int sum(vector<int> &nums, int start, int step) const {
        int s = 0;
        for (int i = start; i < nums.size(); i += step) {
            s += nums[i];
            if (s >= MOD) s -= MOD;
        }
        return s;
    }

public:
    vector<int> solve(vector<int> &nums, vector<vector<int>> &queries) {
        int n = (int) nums.size();
        int len = (int) sqrt(n) / 4;
        int memo[n + len + 1][len + 1];

        memset(memo, -1, sizeof memo);
        for (int i = n + 1; i < n + len + 1; i++) {
            for (int j = 1; j <= len; j++) {
                memo[i][j] = 0;
            }
        }
        vector<int> ans;
        for (auto &q: queries) {
            int start = q[0], step = q[1];
            if (step > len) {
                ans.push_back(sum(nums, start, step));
            } else {
                if (memo[start + 1][step] == -1) {
                    memo[start + 1][step] = 0;
                    for (int i = 1; i <= len; i++) {
                        for (int j = n + 1 - i; j >= 1; j -= step) {
                            memo[j][step] = (nums[j - 1] + memo[j + step][step]) % MOD;
                        }
                    }
                }
                ans.push_back(memo[start + 1][step]);
            }
        }
        return ans;
    }
};