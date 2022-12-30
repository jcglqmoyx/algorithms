#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        int n = (int) capacity.size();
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; i++) {
            v.push_back(capacity[i] - rocks[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                continue;
            }
            if (additionalRocks >= v[i]) {
                additionalRocks -= v[i];
            } else {
                return i;
            }
        }
        return n;
    }
};