#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            if (i & 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end());
        vector<int> res;
        for (int i = 0, j = 0; i < even.size(); i++, j++) {
            res.push_back(even[i]);
            if (j < odd.size()) res.push_back(odd[j]);
        }
        return res;
    }
};