#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int s = 0;
        for (int num: nums) s ^= num;
        int div = 1;
        while ((div & s) == 0) {
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