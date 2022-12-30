#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<int> &s, int k, double mx) {
        int n = (int) s.size();
        for (int i = 0; i < n - 1; i++) {
            double dist = s[i + 1] - s[i];
            if (dist > mx) {
                int need = floor(dist / mx);
                if (need > k) return false;
                k -= need;
            }
        }
        return true;
    }

    double minmaxGasDist(vector<int> &stations, int k) {
        double l = 0, r = 1e8;
        while (r - l >= 1e-6) {
            double mid = (l + r) / 2;
            if (check(stations, k, mid)) r = mid;
            else l = mid;
        }
        return l;
    }
};