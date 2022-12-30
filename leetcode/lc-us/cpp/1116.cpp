#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int count;
    sem_t zeroSem;
    sem_t evenSem;
    sem_t oddSem;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->count = 0;
        // 初始化三个信号量
        // zeroSem 的初始值设为 1, 这样 zeroSem 可以先执行, 且执行完后, 需要等待 sem_post(&zeroSem)才能继续执行;
        // evenSem/oddSem 初始值设为 0, 这样在 zero() 线程调用 sem_post() 前, 都会进入阻塞状态
        sem_init(&zeroSem, 0, 1);
        sem_init(&evenSem, 0, 0);
        sem_init(&oddSem, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            sem_wait(&zeroSem);
            printNumber(0);
            ++count;
            if (count % 2 != 0) {
                sem_post(&oddSem);
            } else {
                sem_post(&evenSem);
            }
        }

    }

    void even(function<void(int)> printNumber) {
        for (int i = 0; i < (n / 2); i++) {
            sem_wait(&evenSem);
            printNumber(count);
            sem_post(&zeroSem);
        }

    }

    void odd(function<void(int)> printNumber) {
        // 奇数执行次数, 使用向上取整
        for (int i = 0; i < (int) ceil(n / 2.0); i++) {
            sem_wait(&oddSem);
            printNumber(count);
            sem_post(&zeroSem);
        }

    }
};