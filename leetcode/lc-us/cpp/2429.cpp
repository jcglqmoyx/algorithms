class Solution {
public:
    int minimizeXor(int n, int m) {
        int c1 = __builtin_popcount(n), c2 = __builtin_popcount(m);
        while (c1 > c2) n &= n - 1, c2++;
        while (c1 < c2) n |= n + 1, c1++;
        return n;
    }
};
