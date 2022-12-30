#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        const int INF = 1e9;
        int res = INF, sum = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum - nums[i] >= target) sum -= nums[i++];
            if (sum >= target) res = min(res, j - i + 1);
        }
        if (res == INF) return 0;
        return res;
    }
};