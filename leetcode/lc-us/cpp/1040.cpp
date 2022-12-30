#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int> &stones) {
        int n = (int) stones.size();
        sort(stones.begin(), stones.end());
        vector<int> res = {n, 0};

        for (int j = 0, i = 0; j < n; j++) {
            if (stones[j] - stones[i] + 1 > n) i++;
            int m = j - i + 1;
            int r;
            if (m == n || m <= n - 2) {
                r = n - m;
            } else if (m == n - 1) {
                if (stones[j] - stones[i] - (m - 1) == 1) {
                    r = 1;
                } else {
                    r = 2;
                }
            }
            res[0] = min(res[0], r);
        }

        int blank = stones.back() - stones.front() - (n - 1);
        res[1] = blank - min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);
        return res;
    }
};