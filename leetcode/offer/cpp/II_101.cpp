#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        bitset<10001> f;
        f[0] = true;
        for (int x: nums) {
            f |= f << x;
            sum += x;
        }
        if (sum & 1) return false;
        return f[sum >> 1];
    }
};