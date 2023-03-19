/*
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        bool st[1001]{};
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) {
                res++;
                return;
            }
            dfs(i + 1);
            if (nums[i] - k <= 0 || !st[nums[i] - k]) {
                st[nums[i]] = true;
                dfs(i + 1);
                st[nums[i]] = false;
            }
        };
        dfs(0);
        return res - 1;
    }
};
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int> &nums, int k) {
        unordered_map<int, map<int, int>> hash;
        for (int x: nums) hash[x % k][x]++;
        int res = 1;
        for (auto &[_, m]: hash) {
            int f0 = 1, f1 = (1 << m.begin()->second) - 1;
            int last = m.begin()->first;
            for (auto it = next(m.begin()); it != m.end(); it++) {
                int now = it->first, cnt = it->second;
                int g0 = f0 + f1, g1;
                if (now - last == k) g1 = f0 * ((1 << cnt) - 1);
                else g1 = (f0 + f1) * ((1 << cnt) - 1);
                f0 = g0, f1 = g1;
                last = now;
            }
            res *= (f0 + f1);
        }
        return res - 1;
    }
};
