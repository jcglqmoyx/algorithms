#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMagicIndex(vector<int> &nums) {
        for (int i = 0; i < nums.size();) {
            if (i == nums[i]) return i;
            else if (i < nums[i]) i = nums[i];
            else i++;
        }
        return -1;
    }
};