#include <bits/stdc++.h>

using namespace std;

class ATM {
    using LL = long long;
    vector<LL> cnt;
    vector<int> money;
public:
    ATM() {
        cnt.resize(5);
        money = {20, 50, 100, 200, 500};
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            cnt[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<LL> temp = cnt;
        vector<int> res(5);
        int i = 4;
        while (amount && ~i) {
            if (temp[i] && amount >= money[i]) {
                LL t = min(temp[i], (LL) amount / money[i]);
                temp[i] -= t;
                amount -= (int) t * money[i];
                res[i] = (int) t;
            }
            i--;
        }
        if (amount) return {-1};
        cnt = temp;
        return res;
    }
};