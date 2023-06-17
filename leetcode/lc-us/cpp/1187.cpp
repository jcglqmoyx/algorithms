#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        constexpr int INF = 0x3f3f3f3f;
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        arr1.insert(arr1.begin(), -1);
        arr1.push_back(INF);
        int n = (int) arr1.size(), m = (int) arr2.size();

        int dp[n];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }
            for (int j = 1; j < i; j++) {
                int k = upper_bound(arr2.begin(), arr2.end(), arr1[i - j - 1]) - arr2.begin();
                if (k + j - 1 < m && arr2[k + j - 1] < arr1[i]) {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }

        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};