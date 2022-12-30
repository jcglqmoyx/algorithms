#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int> &A) {
        int map[1001] = {};
        for (int n: A) map[n]++;
        for (int i = 1000; i >= 0; i--) if (map[i] == 1) return i;
        return -1;
    }
};