#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int x = 0;
        while (mainTank) {
            int t = mainTank / 5;
            int dt = min(t, additionalTank);
            x += t * 5;
            mainTank -= t * 5;
            additionalTank -= dt;
            mainTank += dt;
            if (mainTank < 5) {
                x += mainTank;
                break;
            }
        }
        return x * 10;
    }
};