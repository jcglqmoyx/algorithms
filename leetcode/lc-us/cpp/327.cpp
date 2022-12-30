#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    int m;
    vector<int> tr;

    int lowbit(int x) {
        return x & -x;
    }

    LL query(int x) {
        LL res = 0;
        while (x) {
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }

    void update(int x) {
        while (x <= m) {
            tr[x] += 1;
            x += lowbit(x);
        }
    }

    int get(vector<LL> &s, LL val) {
        return (int) (lower_bound(s.begin(), s.end(), val) - s.begin()) + 1;
    }

public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = (int) nums.size();
        vector<LL> s(n + 1);
        vector<LL> seg;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
            seg.push_back(s[i]);
            seg.push_back(s[i] - upper - 1);
            seg.push_back(s[i] - lower);
        }
        sort(seg.begin(), seg.end());
        seg.erase(unique(seg.begin(), seg.end()), seg.end());

        m = (int) seg.size();
        tr.resize(m + 1);

        int res = 0;
        update(get(seg, 0));
        for (int i = 1; i <= n; i++) {
            res += (int) (query(get(seg, s[i] - lower)) - query(get(seg, s[i] - upper - 1)));
            update(get(seg, s[i]));
        }
        return res;
    }
};