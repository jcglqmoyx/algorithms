#include <bits/stdc++.h>

using namespace std;

class H2O {
    atomic<int> h = 0;
public:
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        while (h == 2) {
            this_thread::yield();
        }
        releaseHydrogen();
        ++h;
    }

    void oxygen(function<void()> releaseOxygen) {
        while (h != 2) {
            this_thread::yield();
        }
        releaseOxygen();
        h = 0;
    }
};