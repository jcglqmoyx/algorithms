#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int> &deck) {
        int size = (int) deck.size();
        int map[10001] = {0};
        for (int card: deck) {
            map[card]++;
        }
        for (int i = 2; i <= size; i++) {
            if (size % i == 0) {
                bool flag = true;
                for (int count: map) {
                    if (count % i != 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};