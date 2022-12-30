const int N = 4010;

class MyCircularDeque {
    bool not_full() {
        return tt - hh + 1 < size;
    }

    int dq[N];
    int size;
    int hh, tt;
public:
    MyCircularDeque(int k) {
        size = k;
        hh = 2005, tt = 2004;
    }

    bool insertFront(int value) {
        if (!not_full()) return false;
        dq[--hh] = value;
        return true;
    }

    bool insertLast(int value) {
        if (!not_full()) return false;
        dq[++tt] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        hh++;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        tt--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return dq[hh];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return dq[tt];
    }

    bool isEmpty() {
        return tt - hh + 1 == 0;
    }

    bool isFull() {
        return tt - hh + 1 == size;
    }
};