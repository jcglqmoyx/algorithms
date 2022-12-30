class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 0;
        int level = 0;
        while (sum + (level + 1) * (level + 2) / 2 <= n) {
            sum += (level + 1) * (level + 2) / 2;
            level++;
        }
        int t = n - sum;
        int x = 0;
        while (t - x > 0) {
            t -= x;
            x++;
        }
        return level * (level + 1) / 2 + x;
    }
};