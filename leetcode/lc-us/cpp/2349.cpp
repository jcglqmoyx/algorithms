#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
    unordered_map<int, int> index2number;
    unordered_map<int, set<int>> number2index;
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (!index2number.count(index)) {
            index2number[index] = number;
            number2index[number].insert(index);
        } else {
            int old_number = index2number[index];
            auto it = number2index.find(old_number);
            it->second.erase(index);
            if (it->second.empty()) number2index.erase(it);
            index2number[index] = number;
            number2index[number].insert(index);
        }
    }

    int find(int number) {
        auto it = number2index.find(number);
        if (it == number2index.end()) return -1;
        return *it->second.begin();
    }
};