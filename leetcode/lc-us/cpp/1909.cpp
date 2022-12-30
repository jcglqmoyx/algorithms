#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int> &nums) {
        int n = (int) nums.size();
        bool flag = true;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                flag = false;
                cnt++;
            }
        }
        if (cnt > 1) return false;
        if (flag) return true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                if (i == 0 || i == n - 2 || nums[i - 1] < nums[i + 1] || i < n - 2 && nums[i] < nums[i + 2]) {
                    return true;
                }
            }
        }
        return false;
    }
};