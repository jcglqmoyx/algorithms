#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> positions;
        positions.insert(to_string(0) + "." + to_string(0));
        for (char move: path) {
            switch (move) {
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
                case 'S':
                    y--;
                    break;
                case 'N':
                    y++;
                    break;
                default:
                    break;
            }
            string position = to_string(x) + "." + to_string(y);
            if (positions.count(position)) {
                return true;
            }
            positions.insert(position);
        }
        return false;
    }
};