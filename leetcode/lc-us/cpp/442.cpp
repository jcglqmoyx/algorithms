#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> duplicates;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (nums[nums[i] - 1] < 0) {
                    duplicates.push_back(nums[i]);
                }
                nums[nums[i] - 1] *= -1;
            } else {
                if (nums[nums[i] * -1 - 1] < 0) {
                    duplicates.push_back(nums[i] * -1);
                }
                nums[nums[i] * -1 - 1] *= -1;
            }
        }
        return duplicates;
    }
};