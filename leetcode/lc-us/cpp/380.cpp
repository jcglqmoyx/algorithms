#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
    int ptr = 0;
    vector<int> nums;
    unordered_map<int, int> map;
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        map[val] = ptr++;
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        int n = nums.size();
        int index = map[val];
        map[nums.back()] = index;
        swap(nums[index], nums[n - 1]);
        nums.pop_back();
        ptr--;
        map.erase(val);
        return true;
    }

    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};