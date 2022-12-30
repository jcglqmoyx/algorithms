#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        int longest_time = 0;
        int pre = 0;
        for (auto &log: logs) {
            int time = log[1] - pre;
            longest_time = max(longest_time, time);
            pre = log[1];
        }
        int id = n;
        pre = 0;
        for (auto &log: logs) {
            int time = log[1] - pre;
            if (time == longest_time && id > log[0]) id = log[0];
            pre = log[1];
        }
        return id;
    }
};