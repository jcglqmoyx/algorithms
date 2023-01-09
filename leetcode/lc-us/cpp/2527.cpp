#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorBeauty(vector<int> &nums) {
        int res = 0;
        for (int x: nums) {
            res ^= x;
        }
        return res;
    }
};