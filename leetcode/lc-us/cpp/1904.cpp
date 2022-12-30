#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int t0 = 60 * stoi(startTime.substr(0, 2)) + stoi(startTime.substr(3, 5));
        int t1 = 60 * stoi(finishTime.substr(0, 2)) + stoi(finishTime.substr(3, 5));
        if (t1 < t0) t1 += 1440;
        t1 = t1 / 15 * 15;
        return max(0, (t1 - t0)) / 15;
    }
};