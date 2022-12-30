#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int n = (int) nums.size(), base = 10000;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= base) continue;
            int k = i, sig = base + i, t = nums[k] > 0;
            int last;
            do {
                int p = ((k + nums[k]) % n + n) % n;
                last = nums[k], nums[k] = sig;
                k = p;
            } while (k != i && nums[k] < base && (t ^ (nums[k] > 0)) == 0);
            if (last % n && nums[k] == sig) return true;
        }
        return false;
    }
};