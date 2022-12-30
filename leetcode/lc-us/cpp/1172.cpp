#include <bits/stdc++.h>

using namespace std;

class DinnerPlates {
    int n;
    map<int, vector<int>> M;
    set<int> S;
public:
    DinnerPlates(int capacity) {
        this->n = capacity;
    }

    void push(int val) {
        if (S.empty()) {
            int idx = (int) M.size();
            M[idx].push_back(val);
            if (this->n > 1) S.insert(idx);
        } else {
            auto it = S.begin();
            M[*it].push_back(val);
            if (M[*it].size() == n) {
                S.erase(it);
            }
        }
    }

    int pop() {
        if (M.empty()) return -1;
        auto it = M.rbegin();
        int res = it->second.back();
        it->second.pop_back();
        if (!it->second.empty()) {
            S.insert(it->first);
        } else {
            S.erase(it->first);
            M.erase(it->first);
        }
        return res;
    }

    int popAtStack(int index) {
        if (!M.count(index)) return -1;
        auto res = M[index].back();
        M[index].pop_back();
        if (M[index].empty()) {
            M.erase(index);
        }
        S.insert(index);
        return res;
    }
};