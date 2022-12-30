#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int low = 0, high = (int) nums.size() - 1;
        while (low < high) {
            while (low < high && nums[low] % 2 == 0) {
                low++;
            }
            while (low < high && nums[high] % 2 == 1) {
                high--;
            }
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
        }
        return nums;
    }
};