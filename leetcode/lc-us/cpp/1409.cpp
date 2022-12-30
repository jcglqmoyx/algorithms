#include <bits/stdc++.h>

using namespace std;

class BIT {
public:
    int n;
    vector<int> arr;

    BIT(int _n) : n(_n), arr(_n) {}

    int low_bit(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += arr[x];
            x -= low_bit(x);
        }
        return res;
    }

    void update(int x, int delta) {
        while (x < n) {
            arr[x] += delta;
            x += low_bit(x);
        }
    }
};

class Solution {
public:
    vector<int> processQueries(vector<int> &queries, int m) {
        int n = (int) queries.size();
        BIT bit(m + n + 1);
        vector<int> positions(m + 1);
        for (int i = 1; i <= m; i++) {
            bit.update(n + i, 1);
            positions[i] = n + i;
        }
        vector<int> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            int position = positions[queries[i]];
            res.push_back(bit.query(position) - 1);
            bit.update(position, -1);
            position = n - i;
            positions[queries[i]] = position;
            bit.update(position, 1);
        }
        return res;
    }
};