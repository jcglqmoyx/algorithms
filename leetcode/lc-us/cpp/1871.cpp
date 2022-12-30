#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = (int) s.size();
        vector<int> f(n + 1), sum(n + 1);
        f[1] = 1;
        sum[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '0' && i > minJump) {
                int l = max(1, i - maxJump), r = i - minJump;
                if (sum[r] > sum[l - 1]) f[i] = 1;
            }
            sum[i] = sum[i - 1] + f[i];
        }
        return f[n];
    }
};