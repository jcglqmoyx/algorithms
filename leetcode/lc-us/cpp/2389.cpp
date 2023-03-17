#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        int n = (int) nums.size(), m = (int) queries.size();
        sort(nums.begin(), nums.end());
        int s[n + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        pair<int, int> v[m];
        for (int i = 0; i < m; i++) {
            v[i] = {queries[i], i};
        }
        sort(v, v + m);
        vector<int> res(m);
        for (int i = 0, j = 0; i < m; i++) {
            auto t = v[i];
            int q = t.first, idx = t.second;
            while (j <= n && s[j] <= q) j++;
            res[idx] = j - 1;
        }
        return res;
    }
};