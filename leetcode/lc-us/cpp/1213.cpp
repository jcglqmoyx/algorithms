#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> intersection;
        int map[2001] = {};
        for (int n: arr1) map[n]++;
        for (int n: arr2) map[n]++;
        for (int n: arr3) map[n]++;
        for (int i = 1; i <= 2000; i++) {
            if (map[i] == 3) intersection.push_back(i);
        }
        return intersection;
    }
};