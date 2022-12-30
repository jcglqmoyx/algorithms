#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool check(vector<int> &buckets, int loss, double avg) {
        double less = 0, more = 0;
        for (double x: buckets) {
            if (x > avg) more += x - avg;
            else less += avg - x;
        }
        return more * ((100 - loss) / 100.0) >= less;
    }

public:
    double equalizeWater(vector<int> &buckets, int loss) {
        double l = 0, r = 1e5;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            if (check(buckets, loss, mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};