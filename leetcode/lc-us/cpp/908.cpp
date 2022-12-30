#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int> &nums, int k) {
        int minimum = 10000, maximum = 0;
        for (int num: nums) {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }
        return max(maximum - minimum - 2 * k, 0);
    }
};