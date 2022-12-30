#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int> &arr) {
        int n = (int) arr.size(), cnt = 1;
        bool f[n][2];
        memset(f, false, sizeof f);
        f[n - 1][0] = f[n - 1][1] = true;
        set<pair<int, int>> hash;
        hash.insert({arr[n - 1], n - 1});
        for (int i = n - 2; ~i; i--) {
            auto it = hash.lower_bound({arr[i], -1});
            if (it != hash.end()) {
                int idx = it->second;
                if (f[idx][1]) f[i][0] = true, cnt++;
            }
            it = hash.lower_bound({arr[i], n});
            if (it != hash.begin()) {
                it--;
                int num = it->first;
                it = hash.lower_bound({num, -1});
                if (f[it->second][0]) f[i][1] = true;
            }
            hash.insert({arr[i], i});
        }
        return cnt;
    }
};