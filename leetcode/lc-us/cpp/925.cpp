#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.length()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else {
                if (j > 0 && typed[j] == typed[j - 1]) {
                    while (j < typed.length() && typed[j] == typed[j - 1]) {
                        j++;
                    }
                } else {
                    return false;
                }
            }
        }
        while (j < typed.length()) {
            if (typed[j] != typed[j - 1]) {
                return false;
            }
            j++;
        }
        return true;
    }
};