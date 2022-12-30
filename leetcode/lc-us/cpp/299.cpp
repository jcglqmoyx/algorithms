#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int n = (int) secret.size();
        int cs[10] = {0}, cg[10] = {0};
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                cs[secret[i] - '0']--;
                cg[guess[i] - '0']--;
            }
            cs[secret[i] - '0']++;
            cg[guess[i] - '0']++;
        }
        for (int i = 0; i <= 9; i++) {
            cows += min(cs[i], cg[i]);
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};