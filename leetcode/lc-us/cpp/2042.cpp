#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string word;
        int last = -1e9;
        while (ss >> word) {
            if (isdigit(word[0])) {
                int num = stoi(word);
                if (num <= last) return false;
                last = num;
            }
        }
        return true;
    }
};