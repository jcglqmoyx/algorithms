#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int flag = -1, res = 1, n = (int) nums.size();
        for (int i = 0, j = 0; j < n; j++) {
            if (nums[j] == 1) {
                res = max(res, j - i + 1);
            } else {
                res = max(res, j - flag);
                i = flag + 1;
                flag = j;
            }
        }
        return res;
    }
};