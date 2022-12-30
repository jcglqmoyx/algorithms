#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        long count = 0, len = 1, n = (int) s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                len++;
                if (i == n - 1) {
                    count += len * (len + 1) / 2;
                }
            } else {
                count += len * (len + 1) / 2;
                len = 1;
            }
            count %= 1000000007;
        }
        if (len == 1) count++;
        return (int) count;
    }
};