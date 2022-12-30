#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        quick_select(nums, 0, (int) nums.size() - 1, k);
        return nums[k - 1];
    }

private:
    void quick_select(vector<int> &nums, int low, int high, int k) {
        if (low >= high) return;
        int pivot = nums[low];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && nums[i] > pivot) i++;
            while (j > low && nums[j] < pivot) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
            i++, j--;
        }
        swap(nums[low], nums[j]);
        if (j == k - 1) return;
        else if (j < k - 1) quick_select(nums, j + 1, high, k);
        else quick_select(nums, low, j - 1, k);
    }
};