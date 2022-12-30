#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int low = 0, high = (int) nums.size() - 1;
        for (int i = 0; i <= high; i++) {
            while (i <= high && nums[i] == 2) {
                swap(nums[i], nums[high--]);
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[low++]);
            }
        }
    }
};