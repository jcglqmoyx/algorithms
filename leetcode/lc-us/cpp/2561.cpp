#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < basket1.size(); i++) {
            cnt[basket1[i]]++;
            cnt[basket2[i]]--;
        }
        int mn = INT32_MAX;
        vector<int> v;
        for (auto &[k, c]: cnt) {
            if (c & 1) return -1;
            mn = min(mn, k);
            c = abs(c) / 2;
            while (c--) v.push_back(k);
        }
        nth_element(v.begin(), v.begin() + (int) v.size() / 2, v.end());
        long long res = 0;
        for (int i = 0; i < v.size() / 2; i++) {
            res += min(mn * 2, v[i]);
        }
        return res;
    }
};