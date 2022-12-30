#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int res = 0;
        int end = timeSeries[0];
        for (int t: timeSeries) {
            if (t >= end) {
                res += duration;
            } else {
                res += t + duration - end;
            }
            end = t + duration;
        }
        return res;
    }
};