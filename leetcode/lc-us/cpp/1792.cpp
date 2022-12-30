#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
        using PII = pair<int, int>;
        auto cmp = [&](const PII &a, const PII &b) {
            double dt1 = (double) (a.first + 1) / (a.second + 1) - (double) a.first / a.second;
            double dt2 = (double) (b.first + 1) / (b.second + 1) - (double) b.first / b.second;
            return dt1 < dt2;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
        for (auto &cls: classes) heap.push({cls[0], cls[1]});
        while (extraStudents--) {
            auto t = heap.top();
            heap.pop();
            if (t.first < t.second) t.first++, t.second++, heap.push(t);
            else break;
        }
        double sum = 0;
        int n = (int) classes.size();
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            sum += (double) t.first / t.second;
        }
        return sum / n;
    }
};