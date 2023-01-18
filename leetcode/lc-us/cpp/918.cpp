/***
 * time: O(N), space: O(1)
*/
/*
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = (int) nums.size();
        int res = INT32_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum <= 0) sum = nums[i];
            else sum += nums[i];
            res = max(res, sum);
        }
        sum = 0;
        for (int i = n - 1; i < (n << 1) - 1; i++) {
            if (sum <= 0) sum = nums[i % n];
            else sum += nums[i % n];
            res = max(res, sum);
        }
        int mn = INT32_MAX;
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum >= 0) sum = nums[i];
            else sum += nums[i];
            mn = min(mn, sum);
        }
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == mn) return res;
        return max(res, sum - mn);
    }
};
 */

/***
 * time: O(N), space: O(N), easier to understand
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = (int) nums.size(), res = INT32_MIN;
        int s[n * 2];
        memset(s, 0, sizeof s);
        for (int i = 1; i < n * 2; i++) {
            s[i] = s[i - 1] + nums[(i - 1) % n];
        }
        deque<int> dq = {0};
        for (int i = 1; i < n * 2; i++) {
            while (!dq.empty() && i - dq.front() > n) dq.pop_front();
            if (!dq.empty()) res = max(res, s[i] - s[dq.front()]);
            while (!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
            dq.push_back(i);
        }
        return res;
    }
};