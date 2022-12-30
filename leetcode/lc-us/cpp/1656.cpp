#include <bits/stdc++.h>

using namespace std;

class OrderedStream {
    int size;
    vector<string> arr;
    int p;
public:
    OrderedStream(int n) {
        size = n + 1;
        p = 1;
        arr.resize(size);
    }

    vector<string> insert(int id, string value) {
        arr[id] = move(value);
        vector<string> stream;
        if (arr[p].empty()) return stream;
        else {
            while (p < size && !arr[p].empty()) {
                stream.push_back(arr[p++]);
            }
        }
        return stream;
    }
};