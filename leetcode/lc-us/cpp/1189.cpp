#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {};
        for (char c: text) {
            count[c - 'a']++;
        }
        int balloons = 10000;
        balloons = min(balloons, count['b' - 'a']);
        balloons = min(balloons, count['a' - 'a']);
        balloons = min(balloons, count['l' - 'a'] / 2);
        balloons = min(balloons, count['o' - 'a'] / 2);
        balloons = min(balloons, count['n' - 'a']);
        return balloons;
    }
};