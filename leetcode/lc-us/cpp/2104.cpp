#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        using LL = long long;

        int n = (int) nums.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (stk.empty()) l[i] = -1;
            else l[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; ~i; i--) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) stk.pop();
            if (stk.empty()) r[i] = n;
            else r[i] = stk.top();
            stk.push(i);
        }
        LL res = 0;
        for (int i = 0; i < n; i++) {
            res -= (LL) nums[i] * (i - l[i]) * (r[i] - i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] <= nums[i]) stk.pop();
            if (stk.empty()) l[i] = -1;
            else l[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; ~i; i--) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) stk.pop();
            if (stk.empty()) r[i] = n;
            else r[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; i++) {
            res += (LL) nums[i] * (i - l[i]) * (r[i] - i);
        }
        return res;
    }
};
