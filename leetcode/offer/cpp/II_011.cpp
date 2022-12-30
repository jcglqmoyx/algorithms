#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int s = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) s++;
            else s--;
            if (hash.count(s)) res = max(res, i - hash[s]);
            else hash[s] = i;
        }
        return res;
    }
};