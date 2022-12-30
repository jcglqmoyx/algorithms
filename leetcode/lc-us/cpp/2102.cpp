#include <bits/stdc++.h>

using namespace std;

struct Location {
    string name;
    int score;
};

struct cmp1 {
    bool operator()(const Location &a, const Location &b) const {
        if (a.score != b.score) return a.score < b.score;
        return a.name > b.name;
    }
};

struct cmp2 {
    bool operator()(const Location &a, const Location &b) const {
        if (a.score != b.score) return a.score > b.score;
        return a.name < b.name;
    }
};

class SORTracker {
public:
    SORTracker() {}

    void add(string name, int score) {
        Location location = {move(name), score};
        max_heap.push(location);
        min_heap.push(max_heap.top());
        max_heap.pop();
        max_heap.push(min_heap.top());
        min_heap.pop();
    }

    string get() {
        auto t = max_heap.top();
        max_heap.pop();
        string res = t.name;
        min_heap.push(t);
        return res;
    }

private:
    priority_queue<Location, vector<Location>, cmp1> max_heap;
    priority_queue<Location, vector<Location>, cmp2> min_heap;
};