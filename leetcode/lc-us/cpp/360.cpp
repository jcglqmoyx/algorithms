#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        vector<int> res;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        if (a > 0) {
            for (int low = 0, high = n - 1; low <= high;) {
                if (nums[low] < nums[high]) {
                    res.push_back(nums[high--]);
                } else {
                    res.push_back(nums[low++]);
                }
            }
            reverse(res.begin(), res.end());
        } else {
            for (int low = 0, high = n - 1; low <= high;) {
                if (nums[low] < nums[high]) {
                    res.push_back(nums[low++]);
                } else {
                    res.push_back(nums[high--]);
                }
            }
        }
        return res;
    }
};