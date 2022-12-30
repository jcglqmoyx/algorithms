#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt++;
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= k) j++;
            i = j - 1;
        }
        return cnt;
    }
};