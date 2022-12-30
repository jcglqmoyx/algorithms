#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int low = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (low < nums.size() && nums[low] != val) {
                low++;
            }
            if (nums[i] != val && i > low) {
                swap(nums[low++], nums[i]);
            }
        }
        return low;
    }
};