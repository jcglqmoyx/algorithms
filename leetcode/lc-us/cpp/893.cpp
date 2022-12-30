#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string> &words) {
        unordered_set<string> set;
        for (const string &str: words) {
            set.insert(count(str));
        }
        return (int) set.size();
    }

private:
    string count(const string &str) {
        int count[52] = {};
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - 'a' + (i & 1) * 26]++;
        }
        string res;
        for (int i: count) {
            res += to_string(i + '_');
        }
        return res;
    }
};