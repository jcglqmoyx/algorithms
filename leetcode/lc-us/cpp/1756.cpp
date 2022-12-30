#include <bits/stdc++.h>

using namespace std;

class MRUQueue {
    int nums[4005];
    int n, tr[4005];

    int low_bit(int x) {
        return x & -x;
    }

    int query(int x) {
        int sum = 0;
        while (x) {
            sum += tr[x];
            x -= low_bit(x);
        }
        return sum;
    }

    void update(int x, int dt) {
        while (x <= 4000) {
            tr[x] += dt;
            x += low_bit(x);
        }
    }

public:
    MRUQueue(int _n) {
        n = _n;
        memset(tr, 0, sizeof tr);
        for (int i = 1; i <= n; i++) {
            nums[i] = i;
        }
    }

    int fetch(int k) {
        int l = k, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid - query(mid) < k) l = mid + 1;
            else r = mid;
        }

        nums[++n] = nums[l];
        update(l, 1);

        return nums[l];
    }
};