#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
        int count = 0;
        if (ruleKey == "type") {
            for (vector<string> &item: items) {
                if (item[0] == ruleValue) {
                    count++;
                }
            }
        } else if (ruleKey == "color") {
            for (vector<string> &item: items) {
                if (item[1] == ruleValue) {
                    count++;
                }
            }
        } else {
            for (vector<string> &item: items) {
                if (item[2] == ruleValue) {
                    count++;
                }
            }
        }
        return count;
    }
};