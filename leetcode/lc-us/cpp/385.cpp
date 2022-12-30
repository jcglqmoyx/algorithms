#include <bits/stdc++.h>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
    int i;
public:
    NestedInteger deserialize(string s) {
        i = 0;
        return dfs(s);
    }

    NestedInteger dfs(string &s) {
        NestedInteger res;
        if (s[i] == '[') {
            i++;
            while (s[i] != ']') res.add(dfs(s));
            i++;
            if (i < s.size() && s[i] == ',') i++;
        } else {
            int k = i;
            while (k < s.size() && s[k] != ',' && s[k] != ']') k++;
            res.setInteger(stoi(s.substr(i, k - i)));
            if (k < s.size() && s[k] == ',') k++;
            i = k;
        }
        return res;
    }
};