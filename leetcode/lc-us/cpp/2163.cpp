#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int> &nums) {
        using LL = long long;
        int m = (int) nums.size(), n = m / 3;
        vector<LL> l(m), r(m);
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<>> min_heap;

        LL left_sum = 0, right_sum = 0;
        for (int i = 0; i < n << 1; i++) {
            max_heap.push(nums[i]);
            left_sum += nums[i];
            if (i >= n - 1) {
                if (i >= n) {
                    int t = max_heap.top();
                    max_heap.pop();
                    left_sum -= t;
                }
                l[i] = left_sum;
            }
        }
        for (int i = m - 1; i >= n; i--) {
            min_heap.push(nums[i]);
            right_sum += nums[i];
            if (i <= m - n) {
                if (i < m - n) {
                    int t = min_heap.top();
                    min_heap.pop();
                    right_sum -= t;
                }
                r[i] = right_sum;
            }
        }
        LL res = INT64_MAX;
        for (int i = n - 1; i < n << 1; i++) {
            res = min(res, l[i] - r[i + 1]);
        }
        return res;
    }
};