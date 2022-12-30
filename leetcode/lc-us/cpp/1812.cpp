#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row = coordinates[1] - '0', col = coordinates[0] - 'a';
        return (row + col) % 2 == 0;
    }
};