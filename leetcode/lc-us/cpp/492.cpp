#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int i = (int) sqrt(area); i <= area; i++) {
            if (area % i == 0) {
                return {max(i, area / i), min(i, area / i)};
            }
        }
        return {};
    }
};