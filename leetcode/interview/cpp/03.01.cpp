#include <bits/stdc++.h>

using namespace std;

class TripleInOne {
    vector<int> a;
    int h1, h2, h3;
    int size;
public:
    TripleInOne(int stackSize) {
        a.resize(stackSize * 3);
        size = stackSize;
        h1 = -1, h2 = stackSize - 1, h3 = stackSize * 2 - 1;
    }

    void push(int stackNum, int value) {
        switch (stackNum) {
            case 0:
                if (h1 < size - 1) {
                    a[++h1] = value;
                } else {
                    break;
                }
                break;
            case 1:
                if (h2 < size * 2 - 1) {
                    a[++h2] = value;
                } else {
                    break;
                }
                break;
            case 2:
                if (h3 < a.size() - 1) {
                    a[++h3] = value;
                } else {
                    break;
                }
                break;
            default:
                break;
        }
    }

    int pop(int stackNum) {
        switch (stackNum) {
            case 0:
                if (h1 == -1) {
                    break;
                } else {
                    int t = a[h1];
                    h1--;
                    return t;
                }
            case 1:
                if (h2 == size - 1) {
                    break;
                } else {
                    int t = a[h2];
                    h2--;
                    return t;
                }
            case 2:
                if (h3 == size * 2 - 1) {
                    break;
                } else {
                    int t = a[h3];
                    h3--;
                    return t;
                }
            default:
                break;
        }
        return -1;
    }

    int peek(int stackNum) {
        switch (stackNum) {
            case 0:
                if (h1 == -1) {
                    return -1;
                } else {
                    return a[h1];
                }
            case 1:
                if (h2 == size - 1) {
                    return -1;
                } else {
                    return a[h2];
                }
            case 2:
                if (h3 == size * 2 - 1) {
                    return -1;
                } else {
                    return a[h3];
                }
            default:
                break;
        }
        return -1;
    }

    bool isEmpty(int stackNum) {
        switch (stackNum) {
            case 0:
                return h1 == -1;
            case 1:
                return h2 == size - 1;
            case 2:
                return h3 == size * 2 - 1;
            default:
                return -1;
        }
    }
};