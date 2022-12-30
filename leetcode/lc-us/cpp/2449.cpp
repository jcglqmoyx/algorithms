#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ll = long long;

    ll get(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll res = 0;
        int n = (int) a.size();
        for (int i = 0; i < n; i++) {
            int x = a[i], y = b[i];
            if (x > y) res += (x - y) / 2;
        }
        return res;
    }

public:
    long long makeSimilar(vector<int> &nums, vector<int> &target) {
        int n = (int) nums.size();

        vector<int> o1, o2, e1, e2;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) o1.push_back(nums[i]);
            else e1.push_back(nums[i]);

            if (target[i] & 1) o2.push_back(target[i]);
            else e2.push_back(target[i]);
        }
        return get(o1, o2) + get(e1, e2);
    }
};