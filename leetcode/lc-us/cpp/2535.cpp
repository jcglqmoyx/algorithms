#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int> &nums) {
        int res = 0;
        for (int x: nums) {
            res += x;
            while (x) res -= x % 10, x /= 10;
        }
        return res;
    }
};