#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = (int) nums.size();
        vector<int> buf(n);
        int res = 0;
        int base = 1;
        while (mx >= base) {
            int cnt[10] = {0};
            for (int i = 0; i < n; i++) {
                int digit = nums[i] / base % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; ~i; i--) {
                int digit = nums[i] / base % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            base *= 10;
        }
        for (int i = 1; i < n; i++) res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};