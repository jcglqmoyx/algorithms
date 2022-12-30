class Solution {
public:
    int totalMoney(int n) {
        int k = n / 7;
        int money = (7 * k + 49) * k / 2;
        int mod = n % 7;
        for (int i = 1; i <= mod; i++) {
            money += k + i;
        }
        return money;
    }
};