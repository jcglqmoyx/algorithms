#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        return verify(postorder, 0, (int) postorder.size() - 1);
    }

private:
    bool verify(vector<int> &postorder, int low, int high) {
        if (high - low <= 1) return true;
        int root = postorder[high];
        int ptr = high - 1;
        while (ptr >= low && postorder[ptr] > root) ptr--;
        int temp = ptr;
        while (temp >= low) {
            if (postorder[temp] > root) return false;
            temp--;
        }
        return verify(postorder, low, ptr) && verify(postorder, ptr + 1, high - 1);
    }
};