#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int> &arr, int k) {
        int n = (int) arr.size();
        bool st[100010]{};
        long long res = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int j = i;
            v.clear();
            while (!st[j]) {
                v.push_back(arr[j]);
                st[j] = true;
                j = (j + k) % n;
            }
            if (v.empty()) continue;
            sort(v.begin(), v.end());
            int val = v[v.size() / 2];
            for (int x: v) {
                res += abs(x - val);
            }
        }
        return res;
    }
};