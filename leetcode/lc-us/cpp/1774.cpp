#include <bits/stdc++.h>

using namespace std;

class Solution {
    int res, t;

    void dfs(vector<int> topping_costs, int cur, int index) {
        if (index == topping_costs.size()) return;
        if (abs(cur - t) < abs(res - t) || abs(cur - t) == abs(res - t) && cur < res) {
            res = cur;
        }
        if (cur > t) return;
        dfs(topping_costs, cur, index + 1);
        int a = cur + topping_costs[index];
        if (abs(a - t) < abs(res - t) || abs(a - t) == abs(res - t) && a < res) {
            res = a;
        }
        if (a > t) return;
        dfs(topping_costs, a, index + 1);
        int b = cur + topping_costs[index] * 2;
        if (abs(b - t) < abs(res - t) || abs(b - t) == abs(res - t) && b < res) {
            res = b;
        }
        if (b > t) return;
        dfs(topping_costs, b, index + 1);
    }

public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        res = -1e6, t = target;
        for (int base_cost: baseCosts) {
            if (base_cost == t) {
                res = base_cost;
                break;
            }
            dfs(toppingCosts, base_cost, 0);
        }
        return res;
    }
};