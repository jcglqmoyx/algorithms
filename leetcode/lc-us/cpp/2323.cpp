#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(vector<int> &jobs, vector<int> &workers) {
        sort(jobs.begin(), jobs.end());
        sort(workers.begin(), workers.end());
        int res = 0;
        for (int i = 0; i < jobs.size(); i++) {
            res = max(res, (jobs[i] + workers[i] - 1) / workers[i]);
        }
        return res;
    }
};