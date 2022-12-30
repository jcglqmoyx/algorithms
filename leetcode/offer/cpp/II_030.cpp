#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (pos.count(val)) return false;
        pos[val] = (int) arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!pos.count(val)) return false;
        int idx = pos[val];
        int n = (int) arr.size();
        swap(arr[n - 1], arr[idx]);
        pos.erase(arr[n - 1]);
        if (idx != n - 1) pos[arr[idx]] = idx;
        arr.pop_back();
        return true;
    }

    int getRandom() {
        int idx = rand() % arr.size();
        return arr[idx];
    }

private:
    vector<int> arr;
    unordered_map<int, int> pos;
};