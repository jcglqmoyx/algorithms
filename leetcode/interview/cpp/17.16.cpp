#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int massage(vector<int> &nums) {
        if (nums.empty()) return 0;
        int first = 0, second = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }
        return max(first, second);
    }
};