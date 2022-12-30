#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (count) {
                    return false;
                }
                if ((i > 0 && nums[i - 1] > nums[i + 1]) && (i < nums.size() - 2 && nums[i] > nums[i + 2])) {
                    return false;
                }
                count++;
            }
        }
        return true;
    }
};