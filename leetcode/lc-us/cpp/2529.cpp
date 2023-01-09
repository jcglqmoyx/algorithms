#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int> &nums) {
        int positive = 0, negtive = 0;
        for (int x: nums) {
            if (x > 0) positive++;
            else if (x < 0) negtive++;
        }
        return max(positive, negtive);
    }
};