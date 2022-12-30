#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int x_or_sum = 0;
        for (int n: nums) {
            x_or_sum ^= n;
        }
        int div = 1;
        while ((div & x_or_sum) == 0) {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int n: nums) {
            if (div & n) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return {a, b};
    }
};