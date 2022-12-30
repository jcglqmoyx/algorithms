#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0;
        for (int sum = 0; sum < target || (sum - target) & 1; n++, sum += n);
        return n;
    }
};