#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int n = (int) plants.size();
        int cnt = 0;
        int a = capacityA, b = capacityB;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i == j) {
                if (a >= b) {
                    if (a < plants[i]) cnt++;
                } else {
                    if (b < plants[j]) cnt++;
                }
            } else {
                if (a < plants[i]) a = capacityA - plants[i], cnt++;
                else a -= plants[i];
                if (b < plants[j]) b = capacityB - plants[j], cnt++;
                else b -= plants[j];
            }
        }
        return cnt;
    }
};