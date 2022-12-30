#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        using pdi = pair<double, int>;
        vector<pdi> worker(quality.size());
        for (int i = 0; i < worker.size(); i++) {
            worker[i] = {wage[i] * 1.0 / quality[i], quality[i]};
        }
        sort(worker.begin(), worker.end());
        priority_queue<int> heap;
        double res = 1e18, sum = 0;
        for (auto &w: worker) {
            heap.push(w.second);
            sum += w.second;
            if (heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }
            if (heap.size() == k) {
                res = min(res, sum * w.first);
            }
        }
        return res;
    }
};