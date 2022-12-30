#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        using LL = long long;
        int circle = min(min(xPos, yPos), min(num - 1 - xPos, num - 1 - yPos));
        LL side = num - 1 - circle * 2;
        LL seq = (LL) (num - 1 + side + 2) * circle * 2;
        if (xPos == circle) seq += yPos - circle + 1;
        else if (yPos == circle) seq += side * 3 + circle + side - xPos + 1;
        else if (circle == num - 1 - xPos) seq += side * 2 + circle + side - yPos + 1;
        else if (circle == num - 1 - yPos) seq += side + xPos - circle + 1;
        return (int) ((seq - 1) % 9) + 1;
    }
};