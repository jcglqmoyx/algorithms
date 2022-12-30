#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int cnt = 0, n = (int) nums.size();
        int hash[205] = {0};
        for (int i = 1; i < n - 2; i++) {
            for (int j = 0; j < i; j++) hash[nums[j] + nums[i]]++;
            for (int j = i + 2; j < n; j++) {
                if (nums[j] - nums[i + 1] >= 0) {
                    cnt += hash[nums[j] - nums[i + 1]];
                }
            }
        }
        return cnt;
    }
};