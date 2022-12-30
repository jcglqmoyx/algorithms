#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int j = (tomatoSlices - 2 * cheeseSlices) / 2;
        int s = cheeseSlices - j;
        if (4 * j + 2 * s == tomatoSlices && j >= 0 && s >= 0) return {j, s};
        return {};
    }
};