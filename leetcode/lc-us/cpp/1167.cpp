#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int> &sticks) {
        priority_queue<int, vector<int>, greater<>> heap;
        int res = 0;
        for (int stick: sticks) heap.push(stick);
        while (heap.size() >= 2) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            res += x + y;
            heap.push(x + y);
        }
        return res;
    }
};