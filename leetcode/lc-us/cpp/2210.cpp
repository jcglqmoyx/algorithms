#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int> &nums) {
        int res = 0;
        for (int i = 1, n = (int) nums.size(); i < n - 1; i++) {
            int j = i + 1;
            if (nums[j] == nums[i]) {
                while (j < n - 1 && nums[j] == nums[i]) j++;
            }
            if (j == n) break;
            if (nums[i] > nums[j] && nums[i] > nums[i - 1] || nums[i] < nums[j] && nums[i] < nums[i - 1]) res++;
            i = j - 1;
        }
        return res;
    }
};