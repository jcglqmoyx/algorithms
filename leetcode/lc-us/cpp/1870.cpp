#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MAX = 2e7;

    bool valid(vector<int> &dist, double hour, int speed) {
        double time = 0;
        for (int i = 0; i + 1 < dist.size(); i++) {
            time += (int) ((dist[i] + speed - 1) / speed);
        }
        time += (double) dist.back() / speed;
        return time <= hour;
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int l = 1, r = MAX;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (valid(dist, hour, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == MAX ? -1 : l;
    }
};