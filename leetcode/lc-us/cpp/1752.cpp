#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (count) return false;
                count++;
            }
        }
        if (nums.back() > nums.front() && count) return false;
        return true;
    }
};