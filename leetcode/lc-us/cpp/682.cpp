#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops) {
        int scores = 0;
        vector<int> points;
        for (const string &op: ops) {
            if (op == "+") {
                int score = points.back() + points[(int) points.size() - 2];
                scores += score;
                points.push_back(score);
            } else if (op == "D") {
                int score = points.back() * 2;
                scores += score;
                points.push_back(score);
            } else if (op == "C") {
                scores -= points.back();
                points.pop_back();
            } else {
                int score = stoi(op);
                points.push_back(score);
                scores += score;
            }
        }
        return scores;
    }
};