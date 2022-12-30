#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        int n = (int) difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (size_t i = 0; i < n; i++) {
            jobs[i] = {profit[i], difficulty[i]};
        }
        sort(jobs.begin(), jobs.end(), greater<>());
        sort(worker.begin(), worker.end(), greater<>());
        int res = 0;
        int i = 0;
        for (int w: worker) {
            while (i < n && jobs[i].second > w) i++;
            if (i < n) res += jobs[i].first;
        }
        return res;
    }
};