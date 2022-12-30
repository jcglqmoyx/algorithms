#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSplits(vector<int> &nums) {
        int n = (int) nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res++;
            int GCD = nums[i];
            int j = i + 1;
            while (j < n && GCD > 1) {
                GCD = gcd(GCD, nums[j]);
                if (GCD > 1) j++;
            }
            i = j - 1;
        }
        return res;
    }

private:
    int gcd(int x, int y) {
        return x % y ? gcd(y, x % y) : y;
    }
};