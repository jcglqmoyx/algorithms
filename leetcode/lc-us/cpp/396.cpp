#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        long long sum = 0, val = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            val += i * nums[i];
        }
        long long max_value = val;
        for (int i = 1; i < n; i++) {
            long long temp = val - sum + (long long) nums[(i + n - 1) % n] * n;
            max_value = max(max_value, temp);
            val = temp;
        }
        return (int) max_value;
    }
};