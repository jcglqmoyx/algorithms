#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

class FizzBuzz {
private:
    int n;
    int num;
    sem_t signalNumber;
    sem_t signalFizzBuzz;
    sem_t signalFizz;
    sem_t signalBuzz;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->num = 1;
        sem_init(&signalNumber, 0, 0);
        sem_init(&signalFizzBuzz, 0, 0);
        sem_init(&signalFizz, 0, 0);
        sem_init(&signalBuzz, 0, 0);
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            sem_wait(&signalFizz);
            if (this->num > this->n) {
                break;
            }
            printFizz();
            turn();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            sem_wait(&signalBuzz);
            if (this->num > this->n) {
                break;
            }
            printBuzz();
            turn();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            sem_wait(&signalFizzBuzz);
            if (this->num > this->n) {
                break;
            }
            printFizzBuzz();
            turn();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            if (this->num > this->n) {
                break;
            }
            printNumber(this->num);
            turn();
            sem_wait(&signalNumber);
        }
    }

    void turn() {
        this->num++;
        if (this->num > this->n) {
            sem_post(&signalFizz);
            sem_post(&signalBuzz);
            sem_post(&signalFizzBuzz);
            sem_post(&signalNumber);
        } else {
            if (this->num % 3 == 0) {
                if (this->num % 5 == 0) {
                    sem_post(&signalFizzBuzz);
                } else {
                    sem_post(&signalFizz);
                }
            } else if (this->num % 5 == 0) {
                sem_post(&signalBuzz);
            } else {
                sem_post(&signalNumber);
            }
        }
    }
};