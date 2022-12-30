#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> M;
        for (int x: tasks) M[x]++;
        int res = 0;
        for (auto[k, v]: M) {
            if (v == 1) return -1;
            res += (v + 2) / 3;
        }
        return res;
    }
};