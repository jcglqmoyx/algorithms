#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        auto check = [&](int mid) {
            int f0 = 0, f1 = 0;
            for (int x: nums) {
                if (x > mid) f0 = f1;
                else {
                    int tmp = f1;
                    f1 = max(f0 + 1, f1);
                    f0 = tmp;
                }
            }
            return f1 >= k;
        };
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};