#include <bits/stdc++.h>

#include <ranges>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const;

    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); it++) {
            st.push(*it);
        }
    }

    int next() {
        auto t = st.top();
        st.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while (!st.empty()) {
            auto cur = st.top();
            if (cur.isInteger()) return true;
            st.pop();
            const auto &list = cur.getList();
            for (auto it = list.rbegin(); it != list.rend(); it++) {
                st.push(*it);
            }
        }
        return false;
    }
};