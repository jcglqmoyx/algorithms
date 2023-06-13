#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int> &nums) {
        int mn = *min_element(nums.begin(), nums.end()), mx = *max_element(nums.begin(), nums.end());
        for (int x: nums) {
            if (x != mn && x != mx) return x;
        }
        return -1;
    }
};