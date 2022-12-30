#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int> &nums, int target) {
        int count = 0;
        int n = (int) nums.size();
        if (nums[n / 2] != target) return false;
        for (int i = n / 2; i >= 0; i--)
            if (nums[i] == target) count++;
            else break;
        for (int i = n / 2 + 1; i < n; i++)
            if (nums[i] == target) count++;
            else break;
        return count > n / 2;
    }
};