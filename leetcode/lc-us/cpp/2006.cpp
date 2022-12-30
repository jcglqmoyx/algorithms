#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int> &nums, int k) {
        int res = 0;
        int cnt[101] = {};
        for (int num: nums) {
            int less = num - k, greater = num + k;
            if (less >= 1 && less <= 100) res += cnt[less];
            if (greater >= 1 && greater <= 100) res += cnt[greater];
            cnt[num]++;
        }
        return res;
    }
};