class Solution {
public:
    int clumsy(int n) {
        int a[] = {1, 2, 6, 7};
        if (n <= 4) return a[n - 1];
        if (n % 4 == 0) return n + 1;
        if (n % 4 <= 2) return n + 2;
        return n - 1;
    }
};