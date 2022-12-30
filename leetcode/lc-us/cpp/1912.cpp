#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

struct Movie {
    int shop, movie, price;

    bool operator<(const Movie &t) const {
        if (price != t.price) return price < t.price;
        if (shop != t.shop) return shop < t.shop;
        return movie < t.movie;
    }
};

set<Movie> mv[N];
set<Movie> lent;
map<pair<int, int>, int> pr;

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>> &entries) {
        for (auto &i: mv) i.clear();
        lent.clear();
        pr.clear();
        for (auto &e: entries) {
            int shop = e[0], movie = e[1], price = e[2];
            mv[movie].insert({shop, movie, price});
            pr[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        for (auto &e: mv[movie]) {
            res.push_back(e.shop);
            if (res.size() >= 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        auto it = mv[movie].find({shop, movie, pr[{shop, movie}]});
        lent.insert(*it);
        mv[movie].erase(it);
    }

    void drop(int shop, int movie) {
        auto it = lent.find({shop, movie, pr[{shop, movie}]});
        mv[movie].insert(*it);
        lent.erase(it);
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &e: lent) {
            res.push_back({e.shop, e.movie});
            if (res.size() >= 5) break;
        }
        return res;
    }
};