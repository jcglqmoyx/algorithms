#include <bits/stdc++.h>

using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";
        else {
            if (timestamp < m[key].begin()->first) return "";
            auto t = m[key].upper_bound(timestamp);
            t--;
            return t->second;
        }
    }
};