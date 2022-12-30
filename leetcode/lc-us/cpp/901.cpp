#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
    int index = 0;
    stack<pair<int, int>> s;
public:
    StockSpanner() {
    }

    int next(int price) {
        index++;
        while (!s.empty() && s.top().first <= price) s.pop();
        int res;
        if (!s.empty()) res = index - s.top().second;
        else res = index;
        s.push({price, index});
        return res;
    }
};