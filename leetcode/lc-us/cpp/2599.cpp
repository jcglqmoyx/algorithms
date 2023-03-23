#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makePrefSumNonNegative(vector<int> &nums) {
        int res = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<>> heap;
        for (int x: nums) {
            sum += x;
            heap.push(x);
            if (sum < 0) {
                sum -= heap.top();
                heap.pop();
                res++;
            }
        }
        return res;
    }
};