#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        auto get = [&](int limit) {
            long long res = 0;
            int i = 0, j = n - 1;
            while (i < j) {
                if (nums[i] + nums[j] > limit) j--;
                else res += j - i, i++;
            }
            return res;
        };
        return get(upper) - get(lower - 1);
    }
};