#include <bits/stdc++.h>

using namespace std;

class RandomizedCollection {
    int size = 0;
    unordered_map<int, unordered_set<int>> hash;
    vector<int> nums;

public:
    RandomizedCollection() {
    }

    bool insert(int val) {
        nums.push_back(val);
        hash[val].insert(size);
        size++;
        return hash[val].size() == 1;
    }

    bool remove(int val) {
        auto it = hash.find(val);
        if (it == hash.end()) return false;
        if (nums[size - 1] == val) {
            hash[val].erase(size - 1);
        } else {
            int idx = *it->second.begin();
            int last = nums[size - 1];
            hash[last].erase(size - 1);
            hash[last].insert(idx);
            it->second.erase(idx);
            swap(nums[idx], nums[size - 1]);
        }
        if (it->second.empty()) hash.erase(it);
        nums.pop_back();
        size--;
        return true;
    }

    int getRandom() {
        return nums[rand() % size];
    }
};