#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        vector<int> times;
        times.reserve(timePoints.size());
        for (string &time: timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3));
            times.push_back(hour * 60 + minute);
            times.push_back((hour + 24) * 60 + minute);
        }
        sort(times.begin(), times.end());
        int min_diff = 24 * 60;
        for (int i = 0; i < times.size() - 1; i++) {
            min_diff = min(min_diff, times[i + 1] - times[i]);
        }
        return min_diff;
    }
};