#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a') {
                for (int j = i; j < n && s[j] != 'a'; j++) {
                    s[j]--;
                }
                return s;
            }
        }
        s.back() = 'z';
        return s;
    }
};