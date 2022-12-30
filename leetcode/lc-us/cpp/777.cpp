#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        string a, b;
        int n = (int) start.size();
        for (int i = 0; i < n; i++) {
            if (start[i] != 'X') a += start[i];
            if (end[i] != 'X') b += end[i];
        }
        if (a != b) return false;
        for (int i = 0, j = 0; i < n; i++, j++) {
            while (i < n && start[i] != 'L') i++;
            while (j < n && end[j] != 'L') j++;
            if (i < j) return false;
        }
        for (int i = 0, j = 0; i < n; i++, j++) {
            while (i < n && start[i] != 'R') i++;
            while (j < n && end[j] != 'R') j++;
            if (i > j) return false;
        }
        return true;
    }
};