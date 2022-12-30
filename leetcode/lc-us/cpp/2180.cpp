class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        for (int i = 1; i <= num; i++) {
            int sum = 0;
            int t = i;
            while (t) {
                sum += t % 10;
                t /= 10;
            }
            if (sum & 1) continue;
            cnt++;
        }
        return cnt;
    }
};