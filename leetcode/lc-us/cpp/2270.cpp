#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int> &nums) {
        using LL = long long;
        LL tot = 0;
        for (int x: nums) tot += x;
        LL left = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            left += nums[i];
            if (left >= tot - left) res++;
        }
        return res;
    }
};