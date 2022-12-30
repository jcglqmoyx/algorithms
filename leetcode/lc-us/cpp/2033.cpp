#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>> &grid, int x) {
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<int> nums;
        nums.reserve(n * m);
        for (auto &row: grid) {
            for (int num: row) {
                nums.push_back(num);
            }
        }
        sort(nums.begin(), nums.end());
        int mid = nums[(int) nums.size() / 2];
        int res = 0;
        for (int num: nums) {
            if ((num - mid) % x) return -1;
            res += abs(num - mid) / x;
        }
        return res;
    }
};