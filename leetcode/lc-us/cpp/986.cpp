#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> intersection;
        int m = (int) firstList.size(), n = (int) secondList.size();
        for (int i = 0, j = 0; i < m && j < n;) {
            int low = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);
            if (low <= high) {
                intersection.push_back({low, high});
            }
            if (firstList[i][1] <= secondList[j][1]) i++;
            else if (firstList[i][1] > secondList[j][1]) j++;
        }
        return intersection;
    }
};