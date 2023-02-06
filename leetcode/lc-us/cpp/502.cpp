#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = (int) profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        priority_queue<int> heap;
        int idx = 0;
        int res = w;
        while (k--) {
            while (idx < n && projects[idx].first <= res) heap.push(projects[idx].second), idx++;
            if (heap.empty()) break;
            if (!heap.empty()) {
                res += heap.top();
                heap.pop();
            }
        }
        return res;
    }
};