class ParkingSystem {
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (this->big == 0) {
                    return false;
                } else {
                    this->big--;
                }
                break;
            case 2:
                if (this->medium == 0) {
                    return false;
                } else {
                    this->medium--;
                }
                break;
            case 3:
                if (this->small == 0) {
                    return false;
                } else {
                    this->small--;
                }
                break;
            default:
                break;
        }
        return true;
    }
};