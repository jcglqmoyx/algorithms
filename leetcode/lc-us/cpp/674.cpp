#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = 1;
        int max_len = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                len++;
            } else {
                len = 1;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};