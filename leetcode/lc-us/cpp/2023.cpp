#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfPairs(vector<string> &nums, string target) {
        int cnt = 0, n = (int) nums.size();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j && nums[i] + nums[j] == target) cnt++;
        return cnt;
    }
};