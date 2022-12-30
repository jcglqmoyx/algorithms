#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int n = (int) nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum < target) {
                    count += high - low;
                    low++;
                } else {
                    high--;
                }
            }
        }
        return count;
    }
};