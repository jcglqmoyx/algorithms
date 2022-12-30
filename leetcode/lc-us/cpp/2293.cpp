#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMaxGame(vector<int> &nums) {
        while (nums.size() != 1) {
            int n = (int) nums.size();
            vector<int> v(n / 2);
            for (int i = 0; i < v.size(); i += 2) {
                v[i] = min(nums[i * 2], nums[i * 2 + 1]);
            }
            for (int i = 1; i < v.size(); i += 2) {
                v[i] = max(nums[i * 2], nums[i * 2 + 1]);
            }
            nums = v;
        }
        return nums[0];
    }
};