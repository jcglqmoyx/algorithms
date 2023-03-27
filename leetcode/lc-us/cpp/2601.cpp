#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int> &nums) {
        constexpr static int N = 1010;
        int primes[N / 3], cnt = 1;
        bool st[N]{};
        primes[0] = 0;
        for (int i = 2; i < N; i++) {
            if (!st[i]) primes[cnt++] = i;
            for (int j = 1; primes[j] * i < N; j++) {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0) break;
            }
        }
        for (int i = 0, prev = 0; i < nums.size(); i++) {
            auto it = lower_bound(primes + 1, primes + cnt + 1, nums[i] - prev);
            it--;
            if (nums[i] - *it <= prev) return false;
            prev = nums[i] - *it;
        }
        return true;
    }
};