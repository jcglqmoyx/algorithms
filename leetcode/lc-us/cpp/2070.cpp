#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        sort(items.begin(), items.end());
        int n = (int) items.size();
        vector<int> dp(n);
        int max_beauty = 0;
        for (int i = 0; i < n; i++) {
            max_beauty = max(max_beauty, items[i][1]);
            dp[i] = max_beauty;
        }
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (items[mid][0] > queries[i]) r = mid - 1;
                else l = mid;
            }
            if (items[l][0] <= queries[i]) res[i] = dp[l];
        }
        return res;
    }
};