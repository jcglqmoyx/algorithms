#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int> &nums) {
        int map[10000] = {};
        for (int n: nums) {
            map[n]++;
        }
        for (int i = 0; i < 10000; i++) {
            if (map[i] == nums.size() / 2) {
                return i;
            }
        }
        return 0;
    }
};