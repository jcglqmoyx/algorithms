#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_gcd(int x, int y) {
        if (x % y == 0) return y;
        return get_gcd(y, x % y);
    }

public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide) {
        int gcd = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++) {
            gcd = get_gcd(gcd, numsDivide[i]);
        }
        vector<int> factors;
        for (int i = 1; i * i <= gcd; i++) {
            if (gcd % i == 0) {
                factors.push_back(i);
                if (i * i < gcd) {
                    factors.push_back(gcd / i);
                }
            }
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int x: factors) {
                if (x % nums[i] == 0) return i;
            }
        }
        return -1;
    }
};