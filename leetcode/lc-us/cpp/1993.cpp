#include <bits/stdc++.h>

using namespace std;

class LockingTree {
public:
    LockingTree(vector<int> &parent) {
        p = parent;
        for (int i = 0; i < parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (locked.count(num)) return false;
        locked[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (!locked.count(num) || locked[num] != user) return false;
        locked.erase(num);
        return true;
    }

    bool upgrade(int num, int user) {
        if (locked.count(num)) return false;
        bool flag = false;
        for (int child: children[num]) {
            ask(child, flag);
        }
        if (!flag) return false;
        flag = true;
        int t = num;
        while (t != -1) {
            int parent = p[t];
            if (locked.count(parent)) {
                flag = false;
                break;
            }
            t = p[t];
        }
        if (!flag) return false;
        locked[num] = user;
        for (int child: children[num]) {
            work(child);
        }
        return true;
    }

private:
    vector<int> p;
    unordered_map<int, vector<int>> children;
    unordered_map<int, int> locked;

    void ask(int num, bool &flag) {
        if (locked.count(num)) {
            flag = true;
            return;
        }
        for (int child: children[num]) {
            ask(child, flag);
        }
    }

    void work(int num) {
        if (locked.count(num)) {
            locked.erase(num);
        }
        for (int child: children[num]) {
            work(child);
        }
    }
};
