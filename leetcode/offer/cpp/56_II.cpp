#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int seen_once = 0, seen_twice = 0;
        for (int n: nums) {
            seen_once = ~seen_twice & (seen_once ^ n);
            seen_twice = ~seen_once & (seen_twice ^ n);
        }
        return seen_once;
    }
};