#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int hit = 0;
        int r = 0, y = 0, g = 0, b = 0, r1 = 0, y1 = 0, g1 = 0, b1 = 0;
        for (int i = 0; i < 4; i++) {
            if (solution[i] == guess[i]) hit++;
            switch (solution[i]) {
                case 'R':
                    r++;
                    break;
                case 'Y':
                    y++;
                    break;
                case 'G':
                    g++;
                    break;
                case 'B':
                    b++;
                    break;
            }
            switch (guess[i]) {
                case 'R':
                    r1++;
                    break;
                case 'Y':
                    y1++;
                    break;
                case 'G':
                    g1++;
                    break;
                case 'B':
                    b1++;
                    break;
            }
        }
        return {hit, min(r, r1) + min(y, y1) + min(g, g1) + min(b, b1) - hit};
    }
};