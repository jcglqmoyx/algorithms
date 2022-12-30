#include <bits/stdc++.h>

using namespace std;

class Allocator {
    int sz;
    vector<int> tr;
    unordered_map<int, vector<pair<int, int>>> map;

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
    Allocator(int n) {
        sz = n;
        tr.resize(sz + 1);
    }

    int allocate(int size, int mID) {
        for (int i = 0; i + size <= sz; i++) {
            int l = i + 1, r = i + size;
            if (!(query(r) - query(l - 1))) {
                map[mID].push_back({l, r});
                for (int j = l; j <= r; j++) update(j, 1);
                return l - 1;
            }
        }
        return -1;
    }

    int free(int mID) {
        if (!map.count(mID)) return 0;
        int res = 0;
        for (auto &v: map[mID]) {
            int l = v.first, r = v.second;
            res += r - l + 1;
            for (int i = l; i <= r; i++) {
                update(i, -1);
            }
        }
        map.erase(mID);
        return res;
    }
};