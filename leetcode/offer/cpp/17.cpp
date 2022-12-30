#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> nums(pow(10, n) - 1);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i + 1;
        }
        return nums;
    }
};