class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int num = n + 1;; num++) {
            int cnt[10] = {0};
            int t = num;
            while (num) {
                cnt[num % 10]++;
                num /= 10;
            }
            num = t;
            bool flag = true;
            while (t) {
                int d = t % 10;
                if (cnt[d] != d) {
                    flag = false;
                    break;
                }
                t /= 10;
            }
            if (flag) return num;
        }
    }
};