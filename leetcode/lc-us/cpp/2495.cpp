#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long evenProduct(vector<int> &nums) {
        long long res = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                if (last != -1) {
                    res += last + 1;
                }
            } else {
                res += i + 1;
                last = i;
            }
        }
        return res;
    }
};