#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int> &nums) {
        long long res = 0;
        int i = 0, j = (int) nums.size() - 1;
        while (i <= j) {
            if (i < j) {
                res += stoll(to_string(nums[i]) + to_string(nums[j]));
                i++, j--;
            } else {
                res += nums[i];
                i++;
            }
        }
        return res;
    }
};