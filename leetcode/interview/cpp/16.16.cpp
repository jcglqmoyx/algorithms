#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int> &array) {
        int n = (int) array.size();
        vector<int> nums = array;
        sort(nums.begin(), nums.end());
        vector<int> res = {-1, -1};
        for (int i = 0; i < n; i++) {
            if (nums[i] != array[i]) {
                res[0] = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] != array[i]) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};