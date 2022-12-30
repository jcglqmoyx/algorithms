#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = (int) nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        int ans = n + 1;
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && sums[i] - sums[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && sums[i] <= sums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};