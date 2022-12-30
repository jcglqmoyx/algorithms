#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    bool check(vector<int> &time, LL mid, int t) {
        LL tot = 0;
        for (int x: time) tot += mid / x;
        return tot >= t;
    }

public:
    long long minimumTime(vector<int> &time, int totalTrips) {
        LL l = 1, r = (LL) *min_element(time.begin(), time.end()) * totalTrips;
        while (l < r) {
            LL mid = l + (r - l) / 2;
            if (check(time, mid, totalTrips)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};