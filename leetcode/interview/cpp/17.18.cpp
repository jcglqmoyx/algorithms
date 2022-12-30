#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestSeq(vector<int> &big, vector<int> &small) {
        vector<int> res;
        unordered_map<int, int> need;
        int diff = (int) small.size();
        for (int e: small) need[e]++;
        for (int l = 0, r = 0; r < big.size(); r++) {
            if (need.count(big[r]) && --need[big[r]] >= 0) diff--;
            while (!diff) {
                if (res.empty() || res[1] - res[0] > r - l) res = {l, r};
                if (need.count(big[l]) && ++need[big[l]] > 0) diff++;
                l++;
            }
        }
        return res;
    }
};