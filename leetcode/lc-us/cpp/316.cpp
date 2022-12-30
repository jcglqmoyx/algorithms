#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk;
        int count[26] = {0};
        for (char c: s) {
            count[c - 'a']++;
        }
        bool visited[26] = {false};
        for (char c: s) {
            if (!visited[c - 'a']) {
                while (!stk.empty() && stk.back() > c) {
                    if (count[stk.back() - 'a']) {
                        visited[stk.back() - 'a'] = false;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                stk.push_back(c);
                visited[c - 'a'] = true;
            }
            count[c - 'a']--;
        }
        return stk;
    }
};