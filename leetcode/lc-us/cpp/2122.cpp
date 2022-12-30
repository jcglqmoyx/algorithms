#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> res;
    int st[2005];

    bool check(vector<int> &nums, int diff) {
        memset(st, false, sizeof st);
        int cnt = 0;
        int it = 0;
        for (int i = 0, j = 0, idx = 0; i < n;) {
            while (i < n && st[i]) i++;
            while (j < n && (st[j] || nums[j] - nums[i] != diff)) j++;
            if (i < n && j < n) {
                cnt++;
                res[it++] = nums[i] + (diff >> 1);
                st[j] = true;
                i++, j++;
            } else {
                break;
            }
        }
        return cnt == (n >> 1);
    }

public:
    vector<int> recoverArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        n = (int) nums.size(), res.resize(n >> 1);
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - nums[0];
            if (diff == 0 || diff & 1) continue;
            if (check(nums, diff)) {
                return res;
            }
        }
        return {};
    }
};