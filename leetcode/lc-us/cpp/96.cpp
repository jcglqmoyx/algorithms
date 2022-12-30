class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for (int i = 1; i < n; i++) {
            ans = 2 * (2 * i + 1) * ans / (i + 2);
        }
        return (int) ans;
    }
};