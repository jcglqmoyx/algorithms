#include <bits/stdc++.h>

using namespace std;

class FooBar {
private:
    int n;
    atomic<bool> foo_done = false;
public:
    FooBar(int n) : n(n) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (foo_done) {
                this_thread::yield();
            }
            printFoo();
            foo_done = true;
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (!foo_done) {
                this_thread::yield();
            }
            printBar();
            foo_done = false;
        }
    }
};