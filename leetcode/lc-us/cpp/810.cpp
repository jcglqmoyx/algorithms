#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool xorGame(vector<int> &nums) {
        int s = 0;
        for (int num: nums) s ^= num;
        return !s || nums.size() % 2 == 0;
    }
};