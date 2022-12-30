#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int> &nums) {
        int cnt[510] = {};
        for (int x: nums) {
            cnt[x]++;
        }
        for (int i = 1; i <= 500; i++) {
            if (cnt[i] & 1) return false;
        }
        return true;
    }
};