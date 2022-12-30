#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partition(vector<int> &nums, int low, int high) {
        int pivot = nums[low];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && nums[i] > pivot) i++;
            while (j > low && nums[j] < pivot) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[low], nums[j]);
        return j;
    }

    int findKthLargest(vector<int> &nums, int k) {
        int low = 0, high = (int) nums.size() - 1;
        int position = partition(nums, low, high);
        while (position != k - 1) {
            if (position > k - 1) {
                high = position - 1;
            } else {
                low = position + 1;
            }
            position = partition(nums, low, high);
        }
        return nums[k - 1];
    }
};