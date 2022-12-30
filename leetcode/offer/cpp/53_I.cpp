#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0, high = (int) nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return freq(nums, target, mid);
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return 0;
    }

private:
    int freq(vector<int> &nums, int target, int mid) {
        int count = 1;
        for (int i = mid - 1; i >= 0; i--)
            if (nums[i] == target) count++;
            else break;
        for (int i = mid + 1; i < nums.size(); i++)
            if (nums[i] == target) count++;
            else break;
        return count;
    }
};