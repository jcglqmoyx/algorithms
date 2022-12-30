#include <bits/stdc++.h>

using namespace std;

class ZigzagIterator {
    vector<int> m, n;
    int i = 0, j = 0;
    bool flag = true;
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        m = v1;
        n = v2;
    }

    int next() {
        if (i < m.size() && j < n.size()) {
            if (flag) {
                flag = false;
                return m[i++];
            } else {
                flag = true;
                return n[j++];
            }
        } else if (i < m.size()) {
            return m[i++];
        } else {
            return n[j++];
        }
    }

    bool hasNext() {
        return i < m.size() || j < n.size();
    }
};