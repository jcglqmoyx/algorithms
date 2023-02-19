#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int> &nums) {
        int mask = 0;
        for (int x: nums) {
            if ((x & (x - 1)) == 0) mask |= x;
        }
        mask = ~mask;
        return mask & -mask;
    }
};