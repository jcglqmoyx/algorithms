class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int x = 1 % k, len = 1;
        while (x) x = (x * 10 + 1) % k, len++;
        return len;
    }
};