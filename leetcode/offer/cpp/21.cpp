#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int i = 0, j = 0, n = (int) nums.size();
        for (; j < n; j++) {
            while (j < n && nums[j] % 2 == 1) {
                swap(nums[i++], nums[j]);
                if (i >= j) j++;
            }
        }
        return nums;
    }
};