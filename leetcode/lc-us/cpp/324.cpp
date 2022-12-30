#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int pivot = nums[n / 2];
        int low = 0, ptr = 0, high = n - 1;
        while (ptr < high) {
            if (nums[ptr] > pivot) {
                swap(nums[ptr], nums[high]);
                high--;
            } else if (nums[ptr] < pivot) {
                swap(nums[ptr], nums[low]);
                low++;
                ptr++;
            } else {
                ptr++;
            }
        }
        vector<int> left(nums.begin(), nums.begin() + (n + 1) / 2);
        vector<int> right(nums.begin() + (n + 1) / 2, nums.end());
        int l_size = left.size(), r_size = right.size();
        for (int i = 0; i < l_size; i++) {
            nums[i * 2] = left[l_size - i - 1];
        }
        for (int i = 0; i < r_size; i++) {
            nums[i * 2 + 1] = right[r_size - i - 1];
        }
    }
};