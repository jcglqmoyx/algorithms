#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = (int) password.size();
        if (n < 8) return false;
        int mask = 0;
        string special = "!@#$%^&*()-+";
        for (int i = 0; i < n; i++) {
            if (i && password[i] == password[i - 1]) return false;
            if (islower(password[i])) mask |= 1;
            else if (isupper(password[i])) mask |= 2;
            else if (isdigit(password[i])) mask |= 4;
            else if (find(special.begin(), special.end(), password[i]) != special.end()) mask |= 8;
        }
        return mask == 15;
    }
};