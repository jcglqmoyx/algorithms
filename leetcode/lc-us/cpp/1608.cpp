#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int specialArray(vector<int> &nums) {
        int map[1001] = {};
        for (int num: nums) {
            map[num]++;
        }
        int count = 0;
        for (int i = 1000; i >= 1; i--) {
            if (map[i]) {
                map[i] += count;
                count = map[i];
            } else {
                map[i] = count;
            }
            if (map[i] == i) {
                return i;
            }
        }
        return -1;
    }
};