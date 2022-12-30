#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int> &nums) {
        int min_value = *min_element(nums.begin(), nums.end());
        int max_value = *max_element(nums.begin(), nums.end());
        int min_value_index = -1, max_value_index = -1;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == min_value) {
                min_value_index = i;
                break;
            }
        }
        for (int i = n - 1; ~i; i--) {
            if (nums[i] == max_value) {
                max_value_index = i;
                break;
            }
        }
        int res = min_value_index + n - 1 - max_value_index;
        if (min_value_index > max_value_index) res--;
        return res;
    }
};