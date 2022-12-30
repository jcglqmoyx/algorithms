#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int> &d) {
        int n = (int) d.size();
        if (n <= 3) return false;
        for (int i = 3; i < n; i++) {
            if (d[i] >= d[i - 2] && d[i - 1] <= d[i - 3]) return true;
            if (i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2]) return true;
            if (i >= 5 && d[i - 1] < d[i - 3] && d[i - 1] + d[i - 5] >= d[i - 3] && d[i - 2] > d[i - 4] && d[i] + d[i - 4] >= d[i - 2]) return true;
        }
        return false;
    }
};