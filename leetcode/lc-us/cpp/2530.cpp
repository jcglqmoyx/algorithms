#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int> &nums, int k) {
        priority_queue<int> heap;
        for (int x: nums) heap.push(x);
        long long res = 0;
        while (k--) {
            int t = heap.top();
            heap.pop();
            res += t;
            heap.push((t + 2) / 3);
        }
        return res;
    }
};