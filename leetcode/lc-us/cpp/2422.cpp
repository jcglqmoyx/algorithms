#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        int n = (int) nums.size();
        int i = 0, j = n - 1;
        int res = 0;
        long long l = nums[0], r = nums[n - 1];
        while (i < j) {
            if (l != r) {
                if (l < r) {
                    i++;
                    l += nums[i];
                } else {
                    j--;
                    r += nums[j];
                }
                res++;
            } else {
                i++, j--;
                l = nums[i], r = nums[j];
            }
        }
        return res;
    }
};