#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minBuildTime(vector<int> &blocks, int split) {
        priority_queue<int, vector<int>, greater<>> heap;
        for (int x: blocks) heap.push(x);
        while (heap.size() > 1) {
            heap.pop();
            int t = heap.top();
            heap.pop();
            heap.push(t + split);
        }
        return heap.top();
    }
};