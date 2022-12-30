#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int> nums(arr);
        for (int i = 1; i < nums.size(); i++) {
            nums[i] ^= nums[i - 1];
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < ans.size(); i++) {
            if (queries[i][0] == queries[i][1]) ans[i] = arr[queries[i][0]];
            else if (queries[i][0] == 0) ans[i] = nums[queries[i][1]];
            else ans[i] = nums[queries[i][1]] ^ nums[queries[i][0] - 1];
        }
        return ans;
    }
};