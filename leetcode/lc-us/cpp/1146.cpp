#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
public:
    SnapshotArray(int length) {
        id = 0;
        for (int i = 0; i < length; i++) hash[i][0] = 0;
    }

    void set(int index, int val) {
        hash[index][id] = val;
    }

    int snap() {
        id++;
        return id - 1;
    }

    int get(int index, int snap_id) {
        auto &t = hash[index];
        auto it = t.upper_bound(snap_id);
        it--;
        return it->second;
    }

private:
    int id;
    unordered_map<int, map<int, int>> hash;
};