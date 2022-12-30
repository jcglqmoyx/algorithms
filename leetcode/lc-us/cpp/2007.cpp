#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        const int N = 200005;
        int n = (int) changed.size();
        if (n & 1) return {};
        int hash[N] = {};
        for (int x: changed) hash[x]++;
        sort(changed.begin(), changed.end());
        vector<int> res;
        res.reserve(n >> 1);
        for (int x: changed) {
            if (hash[x]) {
                if (!hash[x << 1]) return {};
                hash[x]--;
                hash[x << 1]--;
                res.push_back(x);
            }
        }
        return res;
    }
};