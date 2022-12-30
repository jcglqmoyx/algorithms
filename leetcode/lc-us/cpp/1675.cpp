#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int> &nums) {
        priority_queue<int> heap;
        int mn = INT32_MAX;
        for (int num: nums) {
            if (num & 1) num <<= 1;
            heap.push(num);
            mn = min(mn, num);
        }
        int res = INT32_MAX;
        while (true) {
            int x = heap.top();
            heap.pop();
            res = min(res, x - mn);
            if (x & 1) break;
            x >>= 1;
            mn = min(mn, x);
            heap.push(x);
        }
        return res;
    }
};