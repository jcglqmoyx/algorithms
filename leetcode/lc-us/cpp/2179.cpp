#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> tr;

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
        while (x <= n) {
            tr[x] += dt;
            x += low_bit(x);
        }
    }

public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
        n = (int) nums1.size();
        tr.resize(n + 1);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[nums1[i]] = i + 1;
        }
        long long res = 0;
        for (int i = 1; i < n - 1; i++) {
            update(p[nums2[i - 1]], 1);
            long long left = query(p[nums2[i]] - 1);
            res += left * (n - i - 1 - (p[nums2[i]] - 1 - left));
        }
        return res;
    }
};
