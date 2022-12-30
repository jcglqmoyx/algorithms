#include <bits/stdc++.h>

using namespace std;

class Bank {
    using LL = long long;
    vector<LL> b;
    int n;
public:
    Bank(vector<long long> &balance) {
        b = balance;
        n = (int) b.size();
    }

    bool transfer(int account1, int account2, long long money) {
        int x = account1 - 1, y = account2 - 1;
        if (x < 0 || x >= n || y < 0 || y >= n) return false;
        if (b[x] < money) return false;
        b[x] -= money, b[y] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account < 1 || account > n) return false;
        b[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account < 1 || account > n) return false;
        if (b[account - 1] >= money) {
            b[account - 1] -= money;
            return true;
        }
        return false;
    }
};