#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int> &arr, int target) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        LL res = 0;
        int n = (int) arr.size();
        for (int i = 0; i < n; i++) {
            int cnt[305] = {0};
            for (int j = i + 1; j < n; j++) {
                int diff = target - arr[i] - arr[j];
                if (diff >= 0 && cnt[diff]) res = (res + cnt[diff]) % MOD;
                cnt[arr[j]]++;
            }
        }
        return (int) res;
    }
};