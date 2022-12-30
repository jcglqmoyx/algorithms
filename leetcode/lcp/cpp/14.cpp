#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums) {
        int min_prime[1000010], prime[100010], g[1000010];
        int n = (int) nums.size(), m = 2;
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
        }
        for (int i = 2; i <= m; i++) {
            if (!min_prime[i]) {
                prime[++prime[0]] = i;
                min_prime[i] = i;
            }
            for (int j = 1; j <= prime[0]; j++) {
                if (i > m / prime[j]) break;
                min_prime[i * prime[j]] = prime[j];
                if (i % prime[j] == 0) break;
            }
        }
        for (int j = 1; j <= prime[0]; j++) g[prime[j]] = n;
        for (int x = nums[0]; x > 1; x /= min_prime[x]) {
            g[min_prime[x]] = 0;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = i + 1;
            for (int x = nums[i]; x > 1; x /= min_prime[x]) {
                ans = min(g[min_prime[x]] + 1, ans);
            }
            if (i == n - 1) break;
            for (int x = nums[i + 1]; x > 1; x /= min_prime[x]) {
                g[min_prime[x]] = min(g[min_prime[x]], ans);
            }
        }
        return ans;
    }
};