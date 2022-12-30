#include <bits/stdc++.h>

using namespace std;

class StreamRank {
    vector<int> arr;
    int n;

    int query(int x) {
        int res = 0;
        while (x) {
            res += arr[x];
            x -= low_bit(x);
        }
        return res;
    }

    void update(int x) {
        while (x <= n) {
            arr[x] += 1;
            x += low_bit(x);
        }
    }

    int low_bit(int x) { return x & -x; }

public:
    StreamRank() {
        n = 50005;
        arr = vector<int>(n);
    }

    void track(int x) {
        update(x + 1);
    }

    int getRankOfNumber(int x) {
        return query(x + 1);
    }
};