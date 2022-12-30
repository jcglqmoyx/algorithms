#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<int> l(n), r(n);
        for (int i = 1; i < n; i++) {
            l[i] = 1;
            if (i >= 2 && nums[i - 2] >= nums[i - 1]) l[i] = l[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            r[i] = 1;
            if (i <= n - 3 && nums[i + 1] <= nums[i + 2]) r[i] = r[i + 1] + 1;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (l[i] >= k && r[i] >= k) {
                res.push_back(i);
            }
        }
        return res;
    }
};