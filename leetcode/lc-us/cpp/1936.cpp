#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addRungs(vector<int> &rungs, int dist) {
        int res = 0;
        int start = 0;
        for (int rung: rungs) {
            if (start + dist < rung) {
                res += (rung - start - 1) / dist;
            }
            start = rung;
        }
        return res;
    }
};