#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int> &nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        return (mx + mx + k - 1) * k / 2;
    }
};