#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int> &nums, int p) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        auto check = [&](int mid) {
            int cnt = 0;
            for (int i = 0; i < n - 1; i++) {
                if (nums[i + 1] - nums[i] <= mid) cnt++, i++;
            }
            return cnt >= p;
        };
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};