#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int> &nums) {
        int minimum = 10000;
        int sum = 0;
        for (int num: nums) {
            sum += num;
            minimum = min(minimum, sum);
        }
        return max(1, -minimum + 1);
    }
};