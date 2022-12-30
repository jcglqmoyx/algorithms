#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        int n = (int) position.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {position[i], speed[i]};
        sort(v.begin(), v.end());
        int fleet = 0;
        double mx = 0;
        for (int i = n - 1; ~i; i--) {
            double t = (double) (target - v[i].first) / v[i].second;
            if (t > mx) {
                mx = t;
                fleet++;
            }
        }
        return fleet;
    }
};