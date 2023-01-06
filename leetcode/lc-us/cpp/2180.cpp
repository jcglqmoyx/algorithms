class Solution {
public:
    int countEven(int num) {
        int q = num / 10;
        int cnt = q * 5 - 1;
        int x = q * 10, y = x, t = 0;
        while (x) t += x % 10, x /= 10;
        if (t & 1) cnt += (num - y + 1) / 2;
        else cnt += (num - y) / 2 + 1;
        return cnt;
    }
};