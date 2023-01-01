#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        int res = 1;
        long long x = 0;
        for (char c: s) {
            int d = c - '0';
            if (d > k) return -1;
            x = x * 10 + d;
            if (x > k) {
                x = d;
                res++;
            }
        }
        return res;
    }
};