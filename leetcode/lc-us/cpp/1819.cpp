#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums) {
        int N = *max_element(nums.begin(), nums.end()) + 1;
        bool S[N];
        memset(S, false, sizeof S);
        for (int x: nums) S[x] = true;
        int res = 0;
        for (int x = 1; x < N; x++) {
            int gcd = -1;
            for (int i = 1; x * i < N; i++) {
                if (S[x * i]) {
                    if (gcd == -1) gcd = x * i;
                    else gcd = __gcd(gcd, x * i);
                }
            }
            if (gcd == x) res++;
        }
        return res;
    }
};