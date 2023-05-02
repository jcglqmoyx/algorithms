#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int> &nums) {
        int n = (int) nums.size(), id[n];
        iota(id, id + n, 0);
        sort(id, id + n, [&](int i, int j) {
            return nums[i] < nums[j];
        });
        long long res = n;
        for (int i = 1; i < n; i++) {
            if (id[i] < id[i - 1]) res += n - i;
        }
        return res;
    }
};