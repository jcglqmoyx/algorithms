#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        long long x = 1;
        int i = 0, cnt = 0;
        while (x <= n) {
            if (i < (int) nums.size() && nums[i] <= x) x += nums[i++];
            else {
                x += x;
                cnt++;
            }
        }
        return cnt;
    }
};