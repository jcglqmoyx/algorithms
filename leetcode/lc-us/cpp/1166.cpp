#include <bits/stdc++.h>

using namespace std;

class FileSystem {
public:
    FileSystem() {
    }

    bool createPath(string path, int value) {
        if (hash.count(path)) return false;
        int idx = (int) path.rfind('/');
        if (idx == 0) {
            hash[path] = value;
            return true;
        }
        string parent = path.substr(0, idx);
        if (hash.count(parent)) {
            hash[path] = value;
            return true;
        } else {
            return false;
        }
    }

    int get(string path) {
        auto it = hash.find(path);
        if (it == hash.end()) return -1;
        else return it->second;
    }

private:
    unordered_map<string, int> hash;
};