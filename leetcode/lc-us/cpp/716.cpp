#include <bits/stdc++.h>

using namespace std;

class MaxStack {
private:
    multimap<int, list<int>::iterator> map;
    list<int> stk;
public:
    MaxStack() {}

    void push(int x) {
        stk.push_back(x);
        map.emplace(x, --stk.end());
    }

    int pop() {
        auto lastIt = --stk.end();
        int ans = *lastIt;
        auto toBeRemovedIt = --map.upper_bound(ans);
        map.erase(toBeRemovedIt);
        stk.erase(lastIt);
        return ans;
    }

    int top() { return stk.back(); }

    int peekMax() { return map.rbegin()->first; }

    int popMax() {
        auto lastMapIt = --map.end();
        auto listIt = lastMapIt->second;
        int ans = *listIt;
        map.erase(lastMapIt);
        stk.erase(listIt);
        return ans;
    }
};