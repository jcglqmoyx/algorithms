#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxPrice(vector<vector<int>> &items, int capacity) {
        sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b) {
            return (double) a[0] / a[1] > (double) b[0] / b[1];
        });
        double res = 0;
        for (int i = 0; i < items.size() && capacity; i++) {
            int price = items[i][0], weight = items[i][1];
            int w = min(weight, capacity);
            capacity -= w;
            res += price * ((double) w / weight);
        }
        return capacity > 0 ? -1 : res;
    }
};