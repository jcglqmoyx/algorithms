#include <bits/stdc++.h>

using namespace std;

class FreqStack {
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> hash;
    int max_frequency = 0;
public:
    FreqStack() {
    }

    void push(int val) {
        cnt[val]++;
        hash[cnt[val]].push(val);
        max_frequency = max(max_frequency, cnt[val]);
    }

    int pop() {
        while (hash[max_frequency].empty()) hash.erase(max_frequency), max_frequency--;
        int t = hash[max_frequency].top();
        hash[max_frequency].pop();
        cnt[t]--;
        return t;
    }
};