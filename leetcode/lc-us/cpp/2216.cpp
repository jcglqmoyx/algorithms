#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int> &nums) {
        int res = 0, n = (int) nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) res++;
            else i++;
        }
        if (n - res & 1) res++;
        return res;
    }
};