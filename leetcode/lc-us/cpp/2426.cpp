#include <bits/stdc++.h>

using namespace std;

class Solution {
    int sz;
    static constexpr int N = 80010;
    int tr[N];

    int low_bit(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= low_bit(x);
        }
        return res;
    }

    void update(int x, int dt) {
        while (x <= sz) {
            tr[x] += dt;
            x += low_bit(x);
        }
    }

public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
        int n = (int) nums1.size();
        sz = N - 1;
        for (int i = 0; i < n; i++) nums1[i] -= nums2[i];
        memset(tr, 0, sizeof tr);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += query(nums1[i] + 40000 + diff);
            update(nums1[i] + 40000, 1);
        }
        return res;
    }
};