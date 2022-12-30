#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr) {
        const int MOD = 1e9 + 7;
        int odd = 0, even = 1, sum = 0, res = 0;
        for (int num: arr) {
            sum += num;
            res = (res + ((sum & 1) ? even : odd)) % MOD;
            if (sum & 1) odd++;
            else even++;
        }
        return res;
    }
};