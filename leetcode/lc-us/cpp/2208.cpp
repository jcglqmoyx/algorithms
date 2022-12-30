#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        double sum = 0, minus = 0;
        for (int x: nums) sum += x;
        int res = 0;
        priority_queue<double> heap;
        for (int x: nums) heap.push(x);
        while (minus < sum / 2) {
            double t = heap.top();
            heap.pop();
            minus += t / 2;
            heap.push(t / 2);
            res++;
        }
        return res;
    }
};