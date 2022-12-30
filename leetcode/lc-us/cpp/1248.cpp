#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int n = (int) nums.size(), res = 0;
        vector<int> l(n, 0), r(n, n);
        deque<int> dq;
        int index = -1;
        for (int i = 0; i < n; i++) {
            l[i] = index;
            if (nums[i] & 1) index = i;
        }
        index = n;
        for (int i = n - 1; i >= 0; i--) {
            r[i] = index;
            if (nums[i] & 1) index = i;
        }
        int cnt_odd = 0;
        for (int i = 0; i < n; i++) {
            dq.push_back(i);
            if (nums[i] & 1) cnt_odd++;
            if (cnt_odd == k) {
                while (nums[dq.front()] % 2 == 0) dq.pop_front();
                res += (dq.front() - l[dq.front()]) * (r[i] - i);
                dq.pop_front();
                cnt_odd--;
            }
        }
        return res;
    }
};