#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int res = 0, cnt = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) cnt++;
            while (cnt > 1) {
                if (nums[i] == 0) cnt--;
                i++;
            }
            res = max(res, j - i);
        }
        return res;
    }
};