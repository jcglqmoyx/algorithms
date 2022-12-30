#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        if (tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        if (power < tokens[0]) return 0;
        int n = (int) tokens.size();
        int score = 0;
        for (int i = 0, j = n - 1; i <= j;) {
            if (power > tokens[i]) power -= tokens[i++], score++;
            else if (power == tokens[i] && i == j) score++, i++;
            else if (power >= 1 && j > i) power += tokens[j--], score--;
            else j--;
        }
        return score;
    }
};