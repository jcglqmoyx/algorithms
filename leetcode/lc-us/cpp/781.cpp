#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int> &answers) {
        if (answers.empty()) return 0;
        unordered_map<int, int> hash;
        int res = 0;
        for (int num: answers) {
            if (num == 0) {
                res += 1;
            } else if (hash.find(num) == hash.end()) {
                res += num + 1;
                hash[num] = num;
            } else {
                hash[num]--;
                if (hash[num] == 0) {
                    hash.erase(num);
                }
            }
        }
        return res;
    }
};