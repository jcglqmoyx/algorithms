#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<>());
        int mx = *max_element(inventory.begin(), inventory.end());
        int l = 1, r = mx;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (valid(inventory, orders, mid)) l = mid;
            else r = mid - 1;
        }
        LL sum = 0;
        for (int &number: inventory) {
            if (number <= l) break;
            sum += (LL)(number + l + 1) * (number - l) / 2;
            orders -= number - l;
        }
        sum += (LL) orders * l;
        return int(sum % MOD);
    }

private:
    using LL = long long;
    const int MOD = 1e9 + 7;

    static bool valid(vector<int> &inventory, int orders, int k) {
        LL sum = 0;
        for (int number: inventory) {
            if (number >= k) sum += number - k + 1;
            else break;
        }
        return sum >= orders;
    }
};