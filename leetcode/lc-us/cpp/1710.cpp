#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), &cmp);
        int units = 0;
        int index = 0;
        while (truckSize > 0) {
            if (index == boxTypes.size()) break;
            int temp = min(truckSize, boxTypes[index][0]);
            truckSize -= temp;
            units += temp * boxTypes[index][1];
            index++;
        }
        return units;
    }
};