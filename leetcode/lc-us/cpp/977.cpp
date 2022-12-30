#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> res(nums.size());
        int i = 0, j = (int) nums.size() - 1;
        int index = j;
        while (i <= j) {
            int x = nums[i] * nums[i];
            int y = nums[j] * nums[j];
            if (x > y) {
                res[index--] = x;
                i++;
            } else {
                res[index--] = y;
                j--;
            }
        }
        return res;
    }
};