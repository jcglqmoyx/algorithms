#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) j++;
            res += i * (j - i) * (n - j);
            i = j - 1;
        }
        return res;
    }
};