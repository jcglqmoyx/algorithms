#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int res = 0, product = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (i <= j && product >= k) product /= nums[i++];
            res += j - i + 1;
        }
        return res;
    }
};