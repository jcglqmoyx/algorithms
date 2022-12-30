#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int> &nums) {
        int n = (int) nums.size();
        int res = 0;
        vector<int> left(n), right(n);
        int l = 0, r = 1e9;
        for (int i = 1; i < n; i++) {
            l = max(l, nums[i - 1]);
            left[i] = l;
        }
        for (int i = n - 2; i >= 0; i--) {
            r = min(r, nums[i + 1]);
            right[i] = r;
        }
        for (int i = 1; i < n - 1; i++) {
            if (left[i] < nums[i] && right[i] > nums[i]) res += 2;
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) res++;
        }
        return res;
    }
};