#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                res += 'G';
            } else if (command.substr(i, 2) == "()") {
                res += 'o';
                i++;
            } else {
                res += "al";
                i += 3;
            }
        }
        return res;
    }
};