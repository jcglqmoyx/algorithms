#include <bits/stdc++.h>

using namespace std;

class ExamRoom {
    int _n;
    set<int> s;
public:
    ExamRoom(int n) {
        _n = n;
    }

    int seat() {
        int p = 0;
        if (!s.empty()) {
            int dist = *s.begin();
            for (auto i = s.begin(); i != s.end(); i++) {
                auto j = i;
                j++;
                if (j != s.end()) {
                    if (dist < (*j - *i) / 2) {
                        dist = (*j - *i) / 2;
                        p = *i + dist;
                    }
                } else {
                    if (dist < _n - 1 - *i) {
                        p = _n - 1;
                    }
                }
            }
        }
        s.insert(p);
        return p;
    }

    void leave(int p) {
        s.erase(p);
    }
};