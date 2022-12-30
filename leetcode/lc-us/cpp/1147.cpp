#include  <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
        using ULL = unsigned long long;
        const int P = 131;
        int n = (int) text.size();
        int l = 0, r = n - 1;
        int res = 0;
        ULL h1 = 0, h2 = 0, base = 1;
        while (l < r) {
            h1 = h1 * P + text[l];
            h2 = h2 + text[r] * base;
            base *= P;
            if (h1 == h2) {
                res += 2, h1 = h2 = 0, base = 1;
            } else {
                if (r - l <= 2) {
                    res++;
                    break;
                }
            }
            l++, r--;
        }
        if (l == r) res++;
        return res;
    }
};