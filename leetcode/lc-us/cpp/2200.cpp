#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
        int n = (int) nums.size();
        vector<int> res;
        int right = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                for (int l = max(right, i - k); l <= min(i + k, n - 1); l++) {
                    res.push_back(l);
                }
                right = i + k + 1;
            }
        }
        return res;
    }
};