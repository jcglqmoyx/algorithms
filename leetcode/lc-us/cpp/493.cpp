#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        w.resize(nums.size());
        return merge_sort(nums, 0, (int) nums.size() - 1);
    }

private:
    vector<int> w;

    int merge_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return 0;
        int mid = (l + r) >> 1;
        int res = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);
        for (int i = l, j = mid + 1; i <= mid; i++) {
            while (j <= r && nums[i] > (long long) nums[j] * 2) j++;
            res += j - mid - 1;
        }
        for (int i = l, j = mid + 1, idx = l; i <= mid || j <= r;) {
            if (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) w[idx++] = nums[i++];
                else w[idx++] = nums[j++];
            } else if (i <= mid) w[idx++] = nums[i++];
            else w[idx++] = nums[j++];
        }
        for (int i = l; i <= r; i++) nums[i] = w[i];
        return res;
    }
};