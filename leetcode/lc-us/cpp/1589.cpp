#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests) {
        int n = (int) nums.size();
        int MOD = 1e9 + 7;
        vector<int> arr(n);
        for (auto &request: requests) {
            arr[request[0]] += 1;
            if (request[1] < n - 1) arr[request[1] + 1] -= 1;
        }
        for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
        sort(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());
        long res = 0;
        for (int i = 0; i < n; i++) res += (long) nums[i] * arr[i];
        res %= MOD;
        return (int) res;
    }
};