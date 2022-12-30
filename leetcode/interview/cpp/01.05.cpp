#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.size() > second.size()) return oneEditAway(second, first);
        int m = (int) first.size(), n = (int) second.size();
        if (n - m > 1) return false;
        if (m == n) {
            for (int i = 0, j = 0; i < m; i++, j++) {
                if (first[i] != second[j]) {
                    return first.substr(i + 1) == second.substr(j + 1);
                }
            }
            return true;
        }
        for (int i = 0, j = 0; i < m; i++, j++) {
            if (first[i] != second[j]) {
                return first.substr(i) == second.substr(j + 1);
            }
        }
        return true;
    }
};