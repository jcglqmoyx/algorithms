#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int> &plants, int capacity) {
        int res = 0;
        int col = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (col >= plants[i]) col -= plants[i], res++;
            else res += (i << 1) + 1, col = capacity - plants[i];
        }
        return res;
    }
};