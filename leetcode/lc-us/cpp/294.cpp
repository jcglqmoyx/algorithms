#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canWin(string currentState) {
        if (currentState.length() < 2) return false;
        for (int i = 0; i < currentState.length() - 1; i++) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                currentState[i] = '-';
                currentState[i + 1] = '-';
                if (!canWin(currentState)) {
                    return true;
                }
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        return false;
    }
};