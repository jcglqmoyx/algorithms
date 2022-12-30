#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        int n = (int) queries.size();
        vector<int> res(n);
        int even_sum = 0;
        for (int num: nums) {
            if ((num & 1) == 0) {
                even_sum += num;
            }
        }
        for (int i = 0; i < n; i++) {
            int index = queries[i][1], val = queries[i][0];
            if (nums[index] % 2 != 0 && val % 2 != 0) {
                even_sum += nums[index] + val;
            } else if (nums[index] % 2 == 0 && val % 2 == 0) {
                even_sum += val;
            } else if (nums[index] % 2 == 0 && val % 2 != 0) {
                even_sum -= nums[index];
            }
            res[i] = even_sum;
            nums[index] += val;
        }
        return res;
    }
};