#include <bits/stdc++.h>

using namespace std;

class SparseVector {
    vector<int> *arr;
    unordered_set<int> indices;
public:
    SparseVector(vector<int> &nums) {
        arr = &nums;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) indices.insert(i);
        }
    }

    int dotProduct(SparseVector &vec) {
        int res = 0;
        for (int i = 0; i < vec.arr->size(); i++) {
            if (indices.count(i)) {
                res += arr->at(i) * vec.arr->at(i);
            }
        }
        return res;
    }
};