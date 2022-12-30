#include <bits/stdc++.h>

using namespace std;

class Solution {
    int _n;
    vector<int> q;

    bool check(int mx) {
        int cnt = 0;
        for (int x: q) {
            while (x > 0) {
                x -= mx;
                cnt++;
            }
        }
        return cnt <= _n;
    }

public:
    int minimizedMaximum(int n, vector<int> &quantities) {
        q = quantities, _n = n;
        int l = 1, r = 1e5;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};