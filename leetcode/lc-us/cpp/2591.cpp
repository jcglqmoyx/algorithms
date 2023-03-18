#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        if (money == (children - 1) * 8 + 4) return children - 2;
        money -= children;
        int res = min(children, money / 7);
        if (money > children * 7) res--;
        return res;
    }
};