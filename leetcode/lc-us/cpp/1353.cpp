#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>> &events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> heap;
        int n = (int) events.size(), i = 0, res = 0, day = 1;
        while (i < n || !heap.empty()) {
            while (i < n && events[i][0] == day) {
                heap.push(events[i][1]);
                i++;
            }
            while (!heap.empty() && heap.top() < day) {
                heap.pop();
            }
            if (!heap.empty()) {
                heap.pop();
                res++;
            }
            day++;
        }
        return res;
    }
};