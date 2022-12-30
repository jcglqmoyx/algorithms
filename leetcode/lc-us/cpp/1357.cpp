#include <bits/stdc++.h>

using namespace std;

class Cashier {
public:
    Cashier(int n, int discount, vector<int> &products, vector<int> &prices) {
        _n = n, _discount = discount;
        for (int i = 0; i < products.size(); i++) _prices[products[i]] = prices[i];
    }

    double getBill(vector<int> product, vector<int> amount) {
        double tot = 0;
        for (int i = 0; i < product.size(); i++) tot += _prices[product[i]] * amount[i];
        if (idx % _n == 0) tot = tot * (100 - _discount) / 100;
        idx++;
        return tot;
    }

private:
    int idx = 1;
    int _n, _discount;
    unordered_map<int, int> _prices;
};