#include <bits/stdc++.h>

using namespace std;

class Solution {
    void quicksort(vector<int> &nums, int low, int high) {
        if (low >= high) return;
        int p = partition(nums, low, high);
        quicksort(nums, low, p - 1);
        quicksort(nums, p + 1, high);
    }

    int partition(vector<int> &nums, int low, int high) {
        int idx = low + rand() % (high - low + 1);
        swap(nums[low], nums[idx]);
        int pivot = nums[low];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && nums[i] < pivot) i++;
            while (j > low && nums[j] > pivot) j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[low], nums[j]);
        return j;
    }

public:
    vector<int> sortArray(vector<int> &nums) {
        quicksort(nums, 0, (int) nums.size() - 1);
        return nums;
    }
};