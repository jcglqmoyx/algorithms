#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        int n = (int) nums.size();
        vector<int> res(n), prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] ^ nums[i];
        }
        for (int i = 0; i < n; i++) {
            int sum = prefix_sum[n - i - 1];
            int k = 0;
            for (int j = maximumBit - 1; ~j; j--) {
                int digit = (sum >> j) & 1;
                k += (digit ^ 1) * (1 << j);
            }
            res[i] = k;
        }
        return res;
    }
};