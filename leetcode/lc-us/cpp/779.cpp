class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        int half = 1 << (n - 2), total = 1 << (n - 1);
        if (n & 1) {
            if (k > half) {
                return kthGrammar(n - 1, total + 1 - k);
            } else {
                return kthGrammar(n - 1, k);
            }
        } else {
            if (k > half) {
                return 1 ^ kthGrammar(n - 1, total + 1 - k);
            } else {
                return kthGrammar(n - 1, k);
            }
        }
    }
};