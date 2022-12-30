#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (int x: asteroids) {
            if (m >= x) {
                m += x;
            } else {
                return false;
            }
        }
        return true;
    }
};