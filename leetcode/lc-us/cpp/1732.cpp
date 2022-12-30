#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> &gain) {
        int altitude = 0;
        int res = 0;
        for (int n: gain) {
            altitude += n;
            res = max(res, altitude);
        }
        return res;
    }
};