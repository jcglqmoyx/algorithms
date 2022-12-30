#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = (int) nums.size();
        int steps = 0;
        int end = 0;
        int max_position = 0;
        for (int i = 0; i < n - 1; i++) {
            max_position = max(nums[i] + i, max_position);
            if (i == end) {
                end = max_position;
                steps++;
            }
        }
        return steps;
    }
};