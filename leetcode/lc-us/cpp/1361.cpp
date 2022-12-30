#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p;
    vector<int> rank;
    int count;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] > rank[py]) swap(px, py);
        p[px] = py;
        rank[py]++;
        count--;
        return true;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        count = n;
        p.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) p[i] = i;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (s.find(leftChild[i]) != s.end() || s.find(rightChild[i]) != s.end()) return false;
            if (leftChild[i] != -1 && !connect(i, leftChild[i])) return false;
            if (rightChild[i] != -1 && !connect(i, rightChild[i])) return false;
            if (leftChild[i] != -1) s.insert(leftChild[i]);
            if (rightChild[i] != -1) s.insert(rightChild[i]);
        }
        return count == 1;
    }
};