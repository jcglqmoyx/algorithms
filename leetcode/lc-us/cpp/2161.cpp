#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        int n = (int) nums.size();
        vector<int> res(n, pivot);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) res[l++] = nums[i];
            else if (nums[i] > pivot) res[r--] = nums[i];
        }
        reverse(res.begin() + r + 1, res.end());
        return res;
    }
};