#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        using LL = long long;
        using PII = pair<int, int>;
        LL res = 0;
        priority_queue<PII, vector<PII>, greater<>> q;
        int n = (int) costs.size();
        for (int i = 0; i < candidates; i++) {
            q.push({costs[i], i});
        }
        for (int i = max(candidates, n - candidates); i < n; i++) {
            q.push({costs[i], i});
        }
        int left = candidates, right = max(candidates, n - candidates) - 1;
        int cnt = 0;
        while (cnt < k) {
            auto t = q.top();
            q.pop();
            res += t.first;
            cnt++;
            if (left <= right) {
                if (t.second < left) {
                    q.push({costs[left], left});
                    left++;
                } else {
                    q.push({costs[right], right});
                    right--;
                }
            }
        }
        return res;
    }
};