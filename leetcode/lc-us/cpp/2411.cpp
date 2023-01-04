#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[j] | x) == nums[j]) break;
                nums[j] |= x;
                res[j] = i - j + 1;
            }
        }
        return res;
    }
};