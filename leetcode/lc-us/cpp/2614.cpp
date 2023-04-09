#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>> &nums) {
        auto is_prime = [](int x) {
            if (x < 2) return false;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };
        int n = (int) nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (is_prime(nums[i][i])) res = max(res, nums[i][i]);
            if (is_prime(nums[i][n - 1 - i])) res = max(res, nums[i][n - 1 - i]);
        }
        return res;
    }
};