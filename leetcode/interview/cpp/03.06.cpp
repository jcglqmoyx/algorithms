#include <bits/stdc++.h>

using namespace std;

class AnimalShelf {
    int time = 0;
    const int CAT = 0;
    const int DOG = 1;
    queue<vector<int>> cats, dogs;
public:
    AnimalShelf() {
    }

    void enqueue(vector<int> animal) {
        int amount = animal[0], type = animal[1];
        if (type == CAT) cats.push({amount, type, time});
        else dogs.push({amount, type, time});
        time++;
    }

    vector<int> dequeueAny() {
        if (cats.empty() && dogs.empty()) return {-1, -1};
        else if (cats.empty()) {
            int amount = dogs.front()[0], type = DOG;
            dogs.pop();
            return {amount, type};
        } else if (dogs.empty()) {
            int amount = cats.front()[0], type = CAT;
            cats.pop();
            return {amount, type};
        } else {
            if (cats.front()[2] < dogs.front()[2]) {
                int amount = cats.front()[0], type = CAT;
                cats.pop();
                return {amount, type};
            } else {
                int amount = dogs.front()[0], type = DOG;
                dogs.pop();
                return {amount, type};
            }
        }
    }

    vector<int> dequeueDog() {
        if (dogs.empty()) return {-1, -1};
        int amount = dogs.front()[0], type = DOG;
        dogs.pop();
        return {amount, type};
    }

    vector<int> dequeueCat() {
        if (cats.empty()) return {-1, -1};
        int amount = cats.front()[0], type = CAT;
        cats.pop();
        return {amount, type};
    }
};