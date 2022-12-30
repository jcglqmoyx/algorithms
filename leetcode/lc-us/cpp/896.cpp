#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &nums) {
        bool increasing = false, decreasing = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (increasing) {
                    return false;
                }
                decreasing = true;
            } else if (nums[i] < nums[i + 1]) {
                if (decreasing) {
                    return false;
                }
                increasing = true;
            }
        }
        return true;
    }
};