class Solution {
public:
    int countVowelPermutation(int n) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        LL a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int j = 0; j < n - 1; j++) {
            LL aa = e;
            LL ee = (a + i) % MOD;
            LL ii = (a + e + o + u) % MOD;
            LL oo = (i + u) % MOD;
            LL uu = a;
            a = aa, e = ee, i = ii, o = oo, u = uu;
        }
        return (int) ((a + e + i + o + u) % MOD);
    }
};