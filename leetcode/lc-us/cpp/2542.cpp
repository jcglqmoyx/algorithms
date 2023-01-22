#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        using LL = long long;
        int n = (int) nums1.size();
        vector<pair<int, int >> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums1[i], nums2[i]};
        }
        LL sum = 0;
        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<>> heap;
        for (int i = 0; i < k; i++) {
            sum += v[i].first;
            heap.push(v[i].first);
        }
        LL res = v[k - 1].second * 1LL * sum;
        for (int i = k; i < n; i++) {
            if (v[i].first > heap.top()) {
                sum += v[i].first - heap.top();
                heap.pop();
                heap.push(v[i].first);
            }
            res = max(res, v[i].second * 1LL * sum);
        }
        return res;
    }
};