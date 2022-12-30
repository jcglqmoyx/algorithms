#include <bits/stdc++.h>

using namespace std;

class StackOfPlates {
    int capability;
    vector<vector<int>> v;
public:
    StackOfPlates(int cap) {
        capability = cap;
    }

    void push(int val) {
        if (capability == 0) return;
        if (v.empty() || v.back().size() == capability) {
            vector<int> stk;
            stk.push_back(val);
            v.push_back(stk);
        } else {
            v.back().push_back(val);
        };
    }

    int pop() {
        if (v.empty() || capability == 0) return -1;
        int res = v.back().back();
        v.back().pop_back();
        if (v.back().empty()) v.pop_back();
        return res;
    }

    int popAt(int index) {
        if (index >= v.size() || capability == 0) return -1;
        int res = v[index].back();
        v[index].pop_back();
        if (v[index].empty()) v.erase(v.begin() + index);
        return res;
    }
};