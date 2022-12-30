#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        vector<pair<int, int>> ve(n);
        for (int i = 0; i < n; i++) {
            ve[i] = {efficiency[i], speed[i]};
        }
        sort(ve.begin(), ve.end(), greater<>());
        LL sum = 0, res = 0;
        priority_queue<int, vector<int>, greater<>> heap;
        for (int i = 0; i < n; i++) {
            res = max(res, (sum + ve[i].second) * ve[i].first);
            heap.push(ve[i].second);
            sum += ve[i].second;
            if (heap.size() == k) {
                sum -= heap.top();
                heap.pop();
            }
        }
        return (int) (res % MOD);
    }
};