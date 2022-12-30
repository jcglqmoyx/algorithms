#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = (int) nums.size();
        int cnt[30] = {};
        vector<int> res(n);
        res.back() = 1;
        for (int k = 0; k < 30; k++) {
            if (nums.back() >> k & 1) {
                cnt[k]++;
            }
        }
        for (int i = n - 2, j = n - 1; i >= 0; i--) {
            for (int k = 0; k < 30; k++) {
                if (nums[i] >> k & 1) {
                    cnt[k]++;
                }
            }
            while (j > i) {
                bool flag = true;
                for (int k = 0; k < 30; k++) {
                    if (nums[j] >> k & 1) {
                        if (cnt[k] < 2) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    for (int k = 0; k < 30; k++) {
                        if (nums[j] >> k & 1) {
                            cnt[k]--;
                        }
                    }
                    j--;
                } else {
                    break;
                }
            }
            res[i] = j - i + 1;
        }
        return res;
    }
};