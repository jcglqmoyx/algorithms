#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        int m = (int) l.size();
        vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            int left = l[i], right = r[i];
            int mn = 1e5, mx = -1e5;
            for (int j = left; j <= right; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
            }
            if ((mx - mn) % (right - left)) res[i] = false;
            else if (mx == mn) res[i] = true;
            else {
                int diff = (mx - mn) / (right - left);
                bool st[mx - mn + 1];
                memset(st, 0, sizeof st);
                for (int j = left; j <= right; j++) {
                    st[nums[j] - mn] = true;
                }
                bool flag = true;
                for (int x = mn + diff; x < mx; x += diff) {
                    if (!st[x - mn]) {
                        flag = false;
                        break;
                    }
                }
                res[i] = flag;
            }
        }
        return res;
    }
};