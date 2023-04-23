#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        int n = (int) nums.size();
        vector<int> res(n - k + 1);
        int cnt[101]{};
        for (int l = 0, r = 0; r < n; r++) {
            int num = nums[r];
            cnt[num + 50]++;
            if (r >= k - 1) {
                int cnt_window = 0;
                for (int p = -50; p <= 50; p++) {
                    if (cnt[p + 50]) cnt_window += cnt[p + 50];
                    if (cnt_window >= x) {
                        if (p < 0) res[l] = p;
                        else res[l] = 0;
                        break;
                    }
                }
                cnt[nums[l] + 50]--;
                l++;
            }
        }
        return res;
    }
};