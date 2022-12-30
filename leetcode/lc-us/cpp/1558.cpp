#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int res = 0;
        int k = 0;
        for (int num: nums) {
            int ones = 0, bits = 0;
            while (num) {
                if (num & 1) {
                    ones++;
                }
                num >>= 1;
                bits++;
            }
            k = max(k, bits);
            res += ones;
        }
        res += k - 1;
        return max(res, 0);
    }
};