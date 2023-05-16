#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int> &derived) {
        int x_or = 0;
        for (int x: derived) {
            x_or ^= x;
        }
        return !x_or;
    }
};