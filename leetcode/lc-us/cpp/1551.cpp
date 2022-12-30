class Solution {
public:
    int minOperations(int n) {
        if (n == 1) {
            return 0;
        }
        int largest_diff = 2 * n - 2;
        int smallest_diff = n % 2 == 1 ? 4 : 2;
        return (largest_diff + smallest_diff) * (n / 2) / 4;
    }
};