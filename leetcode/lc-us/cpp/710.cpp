#include <bits/stdc++.h>

using namespace std;

class Solution {
    int len;
    unordered_map<int, int> hash;
public:
    Solution(int n, vector<int> &blacklist) {
        len = n - (int) blacklist.size();
        unordered_set<int> set;
        for (int x = len; x < n; x++) set.insert(x);
        for (int x: blacklist) set.erase(x);
        auto it = set.begin();
        for (int x: blacklist) {
            if (x < len) hash[x] = *it++;
        }
    }

    int pick() {
        int k = rand() % len;
        auto it = hash.find(k);
        if (it == hash.end()) return k;
        return it->second;
    }
};