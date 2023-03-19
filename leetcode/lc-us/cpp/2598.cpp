#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int> &nums, int value) {
        int cnt[100010]{};
        for (int &x: nums) cnt[(x % value + value) % value]++;
        int mex = 0;
        while (cnt[mex % value]--) mex++;
        return mex;
    }
};