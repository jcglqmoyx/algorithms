#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem {
public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        map2[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        int duration = t - map2[id].second;
        map1[map2[id].first][stationName].first += duration;
        map1[map2[id].first][stationName].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        auto t = map1[startStation][endStation];
        return (double) t.first / t.second;
    }

private:
    unordered_map<string, unordered_map<string, pair<int, int>>> map1;
    unordered_map<int, pair<string, int>> map2;
};