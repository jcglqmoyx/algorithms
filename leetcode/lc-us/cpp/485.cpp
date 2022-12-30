#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int len = 0, max_len = 0;
        for (int num: nums) {
            if (num) {
                len++;
                max_len = max(max_len, len);
            } else {
                len = 0;
            }
        }
        return max_len;
    }
};