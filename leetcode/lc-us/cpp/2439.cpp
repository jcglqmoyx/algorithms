#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int> &nums) {
        using ll = long long;
        int ans = nums[0];
        ll sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] >= (sum + i) / (i + 1)) {
                ans = (int) max((ll) ans, (sum + i) / (i + 1));
            }
        }
        return ans;
    }
};