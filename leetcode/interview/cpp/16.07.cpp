class Solution {
public:
    int maximum(int a, int b) {
        long diff = (long) a - (long) b;
        int k = (int) (diff >> 63);
        return a * (1 + k) - b * k;
    }
};