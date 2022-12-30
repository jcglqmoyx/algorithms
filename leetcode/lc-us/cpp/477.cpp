#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int distance = 0;
        for (int i = 0; i < 32; i++) {
            int count_one = 0;
            for (int &num: nums) {
                if (num & 1) count_one++;
                num >>= 1;
            }
            distance += ((int) nums.size() - count_one) * count_one;
        }
        return distance;
    }
};