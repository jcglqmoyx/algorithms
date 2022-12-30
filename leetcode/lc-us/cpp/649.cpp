#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = (int) senate.size();
        queue<int> r, d;
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while (!r.empty() && !d.empty()) {
            if (r.front() < d.front()) r.push(r.front() + n);
            else d.push(d.front() + n);
            r.pop(), d.pop();
        }
        if (r.empty()) return "Dire";
        else return "Radiant";
    }
};