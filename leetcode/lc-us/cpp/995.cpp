#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            int t = sum[i - 1] - sum[max(i - k, 0)] & 1;
            if (nums[i - 1] == t) {
                if (i + k - 1 > n) return -1;
                sum[i]++;
            }
            sum[i] += sum[i - 1];
        }
        return sum[n];
    }
};