#include <bits/stdc++.h>

using namespace std;

class FoodRatings {
    unordered_map<string, int> fr;

    struct T {
        string food;
        int rating;

        bool operator<(const T &t) const {
            if (rating == t.rating) return food < t.food;
            return rating > t.rating;
        }
    };

    unordered_map<string, set<T>> M1;
    unordered_map<string, string> M2;
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < foods.size(); i++) {
            fr[foods[i]] = ratings[i];
            M1[cuisines[i]].insert({foods[i], ratings[i]});
            M2[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        auto it = M1[M2[food]].find({food, fr[food]});
        fr[food] = newRating;
        M1[M2[food]].erase(it);
        M1[M2[food]].insert({food, newRating});
    }

    string highestRated(string cuisine) {
        return M1[cuisine].begin()->food;
    }
};