#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        using PII = pair<int, int>;
        const int MOD = 1e9 + 7;

        vector<PII> v(n);
        for (int i = 0; i < n; i++) v[i] = {efficiency[i], speed[i]};
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<>> heap;
        long long res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i].second;
            res = max(res, sum * v[i].first);
            heap.push(v[i].second);
            if (i >= k - 1) {
                sum -= heap.top();
                heap.pop();
            }
        }
        return (int) (res % MOD);
    }
};