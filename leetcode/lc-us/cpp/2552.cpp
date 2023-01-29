#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/count-increasing-quadruplets/solutions/2080664/by-destiny-god-4qc6/
class Solution {
public:
    long long countQuadruplets(vector<int> &nums) {
        int n = (int) nums.size();

        int v[n];
        memset(v, 0, sizeof v);

        long long res = 0;

        for (int l = 0; l < n; l++) {
            for (int j = 0; j < l; j++) {
                if (nums[j] < nums[l]) res += v[j];
            }

            for (int j = 0, count = 0, k = l; j < k; j++) {
                if (nums[j] > nums[k]) {
                    v[j] += count;
                }
                count += nums[j] < nums[k];
            }
        }
        return res;
    }
};