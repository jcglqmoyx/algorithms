#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];
        for (int i = 0; i < n; i++) {
            int left = sum[i], right = sum[n] - sum[i + 1];
            if (left == right) return i;
        }
        return -1;
    }
};