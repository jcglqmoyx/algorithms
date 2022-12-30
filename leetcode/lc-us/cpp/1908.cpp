#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool nimGame(vector<int> &piles) {
        int t = 0;
        for (int x: piles) {
            t ^= x;
        }
        return t;
    }
};