#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int> &stones) {
        int cnt[3] = {};
        for (int x: stones) cnt[x % 3]++;
        if (cnt[0] & 1) return cnt[1] - cnt[2] > 2 || cnt[2] - cnt[1] > 2;
        return cnt[1] >= cnt[2] && cnt[2] || cnt[2] >= cnt[1] && cnt[1];
    }
};