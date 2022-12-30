#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        int n = (int) l.size();
        vector<bool> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            if (r[i] - l[i] == 1) {
                res.push_back(true);
                continue;
            }
            vector<int> arr;
            arr.reserve(r[i] - l[i] + 1);
            for (int j = l[i]; j <= r[i]; j++) {
                arr.push_back(nums[j]);
            }
            sort(arr.begin(), arr.end());
            bool flag = true;
            for (int j = 1; j < arr.size() - 1; j++) {
                if (arr[j + 1] - arr[j] != arr[j] - arr[j - 1]) {
                    flag = false;
                    break;
                }
            }
            res.push_back(flag);
        }
        return res;
    }
};