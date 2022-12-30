#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arraySign(vector<int> &nums) {
        int count = 0;
        for (int n: nums) {
            if (n == 0) return 0;
            if (n < 0) count++;
        }
        return count & 1 ? -1 : 1;
    }
};