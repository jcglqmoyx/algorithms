class Solution {
public:
    int paintingPlan(int n, int k) {
        if (n * n == k || k == 0) return 1;
        if (k < n) return 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i * n + j * n - i * j == k) {
                    res += combination(n, i) * combination(n, j);
                }
            }
        }
        return res;
    }

private:
    int combination(int m, int n) {
        int res = 1;
        for (int i = n; i > 0; i--) {
            res *= m--;
        }
        for (int i = n; i > 0; i--) {
            res /= n--;
        }
        return res;
    }
};