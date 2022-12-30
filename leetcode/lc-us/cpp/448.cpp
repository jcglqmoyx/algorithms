#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> disappeared_numbers;
        for (int num: nums) {
            if (num < 0) {
                nums[-num - 1] *= nums[-num - 1] > 0 ? -1 : 1;
            } else {
                nums[num - 1] *= nums[num - 1] > 0 ? -1 : 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                disappeared_numbers.push_back(i + 1);
            }
        }
        return disappeared_numbers;
    }
};