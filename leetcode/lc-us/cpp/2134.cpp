#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int> &nums) {
        int n = (int) nums.size();
        int cnt = 0;
        for (int x: nums) {
            if (x) cnt++;
        }
        if (cnt <= 1 || cnt == n) return 0;
        int res = n, m = n << 1;
        int sum = 0;
        for (int i = 0, j = 0; i < m; i++) {
            if (nums[i % n]) sum++;
            if (i >= cnt - 1) {
                if (i >= cnt) {
                    sum -= nums[j++];
                    if (j == n) j %= n;
                }
                res = min(res, cnt - sum);
            }
        }
        return res;
    }
};