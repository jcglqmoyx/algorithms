#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        int n = (int) nums.size(), m = (int) queries.size();
        sort(nums.begin(), nums.end());
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = (int) (upper_bound(s.begin(), s.end(), queries[i]) - s.begin() - 1);
        }
        return res;
    }
};