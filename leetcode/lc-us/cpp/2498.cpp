#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxJump(vector<int> &stones) {
        int n = (int) stones.size();
        if (n == 2) return stones.back();
        int res = 0;
        for (int i = 2; i < n; i++) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};