#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        using PII = pair<int, int>;
        int n = (int) apples.size();
        priority_queue<PII, vector<PII>, greater<>> heap;
        int cnt = 0;
        for (int i = 0;; i++) {
            if (i >= n && heap.empty()) break;
            if (i < n) heap.push({i + days[i], apples[i]});
            while (!heap.empty() && heap.top().first <= i) heap.pop();
            if (heap.empty()) continue;
            auto t = heap.top();
            heap.pop();
            cnt++;
            if (--t.second) {
                heap.push({t.first, t.second});
            }
        }
        return cnt;
    }
};