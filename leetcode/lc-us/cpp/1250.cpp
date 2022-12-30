#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int> &nums) {
        int gcd = nums[0];
        for (int i = 1; i < (int) nums.size(); i++) {
            gcd = __gcd(gcd, nums[i]);
        }
        return gcd == 1;
    }
};