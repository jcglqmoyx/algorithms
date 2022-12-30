#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums, int k) {
        if (nums.size() == 1) return nums[0] + k;

        using LL = long long;
        const int MOD = 1e9 + 7;

        priority_queue<int, vector<int>, greater<>> heap;
        for (int num: nums) heap.push(num);
        while (k) {
            auto x = heap.top();
            heap.pop();
            auto y = heap.top();
            heap.pop();
            int diff = y - x;
            int dt = min(k, diff);
            dt = max(dt, 1);
            k -= dt, x += dt;
            heap.push(x), heap.push(y);
        }
        LL res = 1;
        while (!heap.empty()) {
            int x = heap.top();
            heap.pop();
            res = res * x % MOD;
        }
        return (int) res;
    }
};