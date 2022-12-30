#include <bits/stdc++.h>

using namespace std;

class TrafficLight {
private:
    bool aGreen = true;
    mutex mtx;
public:
    TrafficLight() {

    }

    void carArrived(
            int carId,                   // ID of the car
            int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
            int direction,               // Direction of the car
            function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
            function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {

        if ((roadId == 1 && aGreen) || (roadId == 2 && !aGreen)) {
            crossCar();
        } else {
            mtx.lock();
            aGreen = !aGreen;
            turnGreen();
            mtx.unlock();
            crossCar();
        }

    }
};