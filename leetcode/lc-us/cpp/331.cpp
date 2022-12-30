#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int n = (int) preorder.size();
        for (int i = 0; i < n;) {
            if (preorder[i] == '#') {
                slots--;
                i++;
                if (slots < 0) return false;
            } else if (isdigit(preorder[i])) {
                while (i < n && isdigit(preorder[i])) i++;
                slots--;
                if (slots < 0) return false;
                slots += 2;
            } else {
                i++;
            }
        }
        return slots == 0;
    }
};