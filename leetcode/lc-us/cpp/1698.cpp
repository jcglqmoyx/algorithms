#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDistinct(string s) {
        using ULL = unsigned long long;
        const int P = 131;

        int n = (int) s.size();
        vector<ULL> h(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
        unordered_set<ULL> hash;
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                ULL hash_code = h[i + len - 1] - h[i - 1] * p[len];
                hash.insert(hash_code);
            }
        }
        return (int) hash.size();
    }
};