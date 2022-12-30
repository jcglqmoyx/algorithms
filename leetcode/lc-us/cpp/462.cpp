#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        int move = 0;
        for (int num: nums) {
            move += abs(num - median);
        }
        return move;
    }
};