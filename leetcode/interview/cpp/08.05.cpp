class Solution {
public:
    int multiply(int A, int B) {
        long product = 0;
        long a = A;
        while (B) {
            if (B & 1) {
                product += a;
            }
            a += a;
            B >>= 1;
        }
        return (int) product;
    }
};