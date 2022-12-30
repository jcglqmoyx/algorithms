#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int map[100001] = {};
        for (int num: nums) {
            if (map[num]) return num;
            map[num]++;
        }
        return 0;
    }
};