#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sortArray(vector<int> &nums) {
        int n = (int) nums.size();
        function<int(int)> get = [&](int x) -> int {
            vector<bool> st(n);
            int circle = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == i || st[i]) continue;
                int j = i;
                circle++;
                while (!st[j]) {
                    st[j] = true;
                    j = nums[j];
                    circle++;
                }
            }
            return circle - 2 * (nums[x] != x);
        };
        int res = get(0);
        for (int &x: nums) {
            x = (x - 1 + n) % n;
        }
        res = min(res, get(n - 1));
        return res;
    }
};