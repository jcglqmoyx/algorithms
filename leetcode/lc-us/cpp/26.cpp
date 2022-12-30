#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int low = 0, count = 0, prev = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != prev) {
                nums[low] = nums[i];
                low++;
                count++;
            }
            prev = nums[i];
        }
        return count;
    }
};