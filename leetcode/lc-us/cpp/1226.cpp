#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class DiningPhilosophers {
    sem_t forks[5];
public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            sem_init(&forks[i], 0, 1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        if (philosopher & 1) {
            sem_wait(&forks[right]);
            sem_wait(&forks[left]);
            pickRightFork();
            pickLeftFork();
        } else {
            sem_wait(&forks[left]);
            sem_wait(&forks[right]);
            pickLeftFork();
            pickRightFork();
        }
        eat();
        putLeftFork();
        putRightFork();
        sem_post(&forks[left]);
        sem_post(&forks[right]);
    }
};