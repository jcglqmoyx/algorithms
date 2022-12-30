#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        using ll = long long;
        int n = (int) s.size();
        ll p = 1, h = 0;
        for (int i = n - 1; i >= n - k; i--) {
            p = p * power % modulo;
            h = (h * power + (s[i] & 31)) % modulo;
        }
        int pos;
        if (p == hashValue) pos = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            h = (h * power + (s[i] & 31) - (s[i + k] & 31) * p % modulo + modulo) % modulo;
            if (h == hashValue) pos = i;
        }
        return s.substr(pos, k);
    }
};