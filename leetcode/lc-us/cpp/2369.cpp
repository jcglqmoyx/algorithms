#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 2) return nums[0] == nums[1];

        bitset<100005> f;
        f[0] = true;

        if (nums[0] == nums[1]) f[2] = true;

        for (int i = 3; i <= n; i++) {
            if (nums[i - 2] == nums[i - 1]) {
                if (f[i - 2]) {
                    f[i] = true;
                    continue;
                }
                if (nums[i - 3] == nums[i - 2]) {
                    if (f[i - 3]) {
                        f[i] = true;
                        continue;
                    }
                }
            }
            if (nums[i - 3] == nums[i - 2] - 1 && nums[i - 2] == nums[i - 1] - 1) {
                if (f[i - 3]) {
                    f[i] = true;
                }
            }
        }
        return f[n];
    }
};