#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sell;
        priority_queue<pair<int, int>> buy;
        long backlog_orders = 0;
        for (vector<int> &order: orders) {
            switch (order[2]) {
                case 0:
                    if (sell.empty()) {
                        buy.push({order[0], order[1]});
                        backlog_orders += order[1];
                    } else {
                        while (order[1]) {
                            auto[price, amount] = sell.top();
                            if (order[0] >= price) {
                                int temp = min(order[1], amount);
                                order[1] -= temp;
                                amount -= temp;
                                backlog_orders -= temp;
                                sell.pop();
                                if (amount) sell.push({price, amount});
                                if (sell.empty()) {
                                    buy.push({order[0], order[1]});
                                    backlog_orders += order[1];
                                    break;
                                }
                            } else {
                                buy.push({order[0], order[1]});
                                backlog_orders += order[1];
                                break;
                            }
                        }
                    }
                    break;
                case 1:
                    if (buy.empty()) {
                        sell.push({order[0], order[1]});
                        backlog_orders += order[1];
                    } else {
                        while (order[1]) {
                            auto[price, amount] = buy.top();
                            if (order[0] <= price) {
                                int temp = min(order[1], amount);
                                order[1] -= temp;
                                amount -= temp;
                                backlog_orders -= temp;
                                buy.pop();
                                if (amount) buy.push({price, amount});
                                if (buy.empty()) {
                                    sell.push({order[0], order[1]});
                                    backlog_orders += order[1];
                                    break;
                                }
                            } else {
                                sell.push({order[0], order[1]});
                                backlog_orders += order[1];
                                break;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        backlog_orders %= 1000000007;
        return (int) backlog_orders;
    }
};