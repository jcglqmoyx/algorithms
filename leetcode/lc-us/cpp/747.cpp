#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int first = 0, second = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > second) {
                if (nums[i] > first) {
                    second = first;
                    first = nums[i];
                    index = i;
                } else {
                    second = nums[i];
                }
            }
        }
        return first >= 2 * second ? index : -1;
    }
};