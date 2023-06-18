#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int> &a) {
        sort(a.begin(), a.end());
        int res = 2e9;
        for (int i = 0; i + 1 < a.size(); i++) {
            res = min(res, a[i + 1] - a[i]);
        }
        return res;
    }
};