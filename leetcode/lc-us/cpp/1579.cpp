#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    vector<int> p;
    vector<int> sz;
    int cnt;

    UnionFind(int n) {
        cnt = n;
        p.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        UnionFind uf1(n + 1), uf2(n + 1);
        int res = 0;
        for (auto &e: edges) {
            if (e[0] == 3) {
                int a = e[1], b = e[2];
                int pa1 = uf1.find(a), pb1 = uf1.find(b);
                int pa2 = uf2.find(a), pb2 = uf2.find(b);
                if (pa1 != pb1) {
                    if (uf1.sz[pa1] > uf1.sz[pb1]) {
                        swap(pa1, pb1);
                        swap(pa2, pb2);
                    }
                    uf1.p[pa1] = pb1;
                    uf1.sz[pb1] += uf1.sz[pa1];
                    uf1.cnt--;
                    uf2.p[pa2] = pb2;
                    uf2.sz[pb2] += uf2.sz[pa2];
                    uf2.cnt--;
                } else {
                    res++;
                }
            }
        }
        for (auto &e: edges) {
            if (e[0] == 1) {
                int a = e[1], b = e[2];
                int pa = uf1.find(a), pb = uf1.find(b);
                if (pa != pb) {
                    if (uf1.sz[pa] > uf1.sz[pb]) {
                        swap(pa, pb);
                    }
                    uf1.p[pa] = pb;
                    uf1.sz[pb] += uf1.sz[pa];
                    uf1.cnt--;
                } else {
                    res++;
                }
            } else if (e[0] == 2) {
                int a = e[1], b = e[2];
                int pa = uf2.find(a), pb = uf2.find(b);
                if (pa != pb) {
                    if (uf2.sz[pa] > uf2.sz[pb]) {
                        swap(pa, pb);
                    }
                    uf2.p[pa] = pb;
                    uf2.sz[pb] += uf2.sz[pa];
                    uf2.cnt--;
                } else {
                    res++;
                }
            }
        }
        if (uf1.cnt != 2 || uf2.cnt != 2) {
            return -1;
        }
        return res;
    }
};