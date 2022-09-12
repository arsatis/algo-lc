class ParkingSystem {
    int arr[3];
public:
    ParkingSystem(int big, int medium, int small) {
        ios_base::sync_with_stdio(0);
        arr[0] = big, arr[1] = medium, arr[2] = small;
    }
    
    bool addCar(int carType) {
        if (arr[carType - 1]-- > 0) return true;
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */