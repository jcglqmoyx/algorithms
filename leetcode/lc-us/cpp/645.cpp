#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> res(2);
        vector<int> count(nums.size() + 1);
        for (int num: nums) {
            count[num]++;
        }
        for (int i = 1; i < count.size(); i++) {
            if (count[i] == 2) {
                res[0] = i;
            } else if (count[i] == 0) {
                res[1] = i;
            }
        }
        return res;
    }
};