#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/count-increasing-quadruplets/solutions/2080664/by-destiny-god-4qc6/
class Solution {
public:
    long long countQuadruplets(vector<int> &nums) {
        int n = (int) nums.size();

        vector<int> v(n, 0);

        long long res = 0;

        for (int l = 0; l < n; l++) {
            for (int j = 0; j < l; j++) {
                if (nums[j] < nums[l]) res += v[j];
            }

            for (int j = 0, count = 0; j < l; j++) {
                if (nums[j] > nums[l]) {
                    v[j] += count;
                }
                count += nums[j] < nums[l];
            }
        }
        return res;
    }
};