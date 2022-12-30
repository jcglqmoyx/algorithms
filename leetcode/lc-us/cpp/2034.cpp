#include <bits/stdc++.h>

using namespace std;

class StockPrice {
public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (tp.count(timestamp)) {
            int old = tp[timestamp];
            prices[old]--;
            if (prices[old] == 0) prices.erase(old);
        }
        prices[price]++;
        tp[timestamp] = price;
        if (timestamp >= cur_time) cur_time = timestamp, cur_price = price;
    }

    int current() {
        return cur_price;
    }

    int maximum() {
        return prices.rbegin()->first;
    }

    int minimum() {
        return prices.begin()->first;
    }

private:
    unordered_map<int, int> tp;
    map<int, int> prices;
    int cur_time = -1, cur_price;
};