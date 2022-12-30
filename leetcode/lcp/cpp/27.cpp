#include <bits/stdc++.h>

using namespace std;

class BlackBox {
private:
    vector<pair<int, int>> group_pos;
    vector<pair<int, int>> group_neg;
    vector<map<int, int>> map;

    void createGroup(int n, int m, int index, int direction) {
        int groupId = (int) map.size();
        int groupLoc = 0;
        map.emplace_back();
        while (!(direction == 1 && group_pos[index].first != -1) &&
               !(direction == -1 && group_neg[index].first != -1)) {
            if (direction == 1) {
                group_pos[index] = {groupId, groupLoc++};
                index = (n + m) * 2 - index;
            } else {
                group_neg[index] = {groupId, groupLoc++};
                if (index <= m * 2) {
                    index = m * 2 - index;
                } else {
                    index = (m * 2 + n) * 2 - index;
                }
            }
            if (index != 0 && index != m && index != m + n && index != m * 2 + n) {
                direction = -direction;
            }
        }
    }

public:
    BlackBox(int n, int m) {
        int cnt = (n + m) * 2;
        group_pos.assign(cnt, {-1, -1});
        group_neg.assign(cnt, {-1, -1});
        for (int i = 0; i < cnt; ++i) {
            if (i != 0 && i != m + n && group_pos[i].first == -1) {
                createGroup(n, m, i, 1);
            }
            if (i != m && i != m * 2 + n && group_neg[i].first == -1) {
                createGroup(n, m, i, -1);
            }
        }
    }

    int open(int index, int direction) {
        if (auto[groupId, groupLoc] = group_pos[index]; groupId != -1) {
            map[groupId].emplace(groupLoc, index);
        }
        if (auto[groupId, groupLoc] = group_neg[index]; groupId != -1) {
            map[groupId].emplace(groupLoc, index);
        }

        auto[groupId, groupLoc] = (direction == 1 ? group_pos[index] : group_neg[index]);
        auto &store = map[groupId];
        if (auto iter = store.upper_bound(groupLoc); iter != store.end()) {
            return iter->second;
        } else {
            return store.begin()->second;
        }
    }

    void close(int index) {
        if (auto[groupId, groupLoc] = group_pos[index]; groupId != -1) {
            map[groupId].erase(groupLoc);
        }
        if (auto[groupId, groupLoc] = group_neg[index]; groupId != -1) {
            map[groupId].erase(groupLoc);
        }
    }
};