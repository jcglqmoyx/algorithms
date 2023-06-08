#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        long long res = 0;
        int n = (int) s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) res += min(i, n - i);
        }
        return res;
    }
};