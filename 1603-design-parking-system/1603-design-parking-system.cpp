class ParkingSystem {
    int arr[4];
public:
    ParkingSystem(int big, int medium, int small) {
        ios_base::sync_with_stdio(0);
        
        arr[1] = big, arr[2] = medium, arr[3] = small;
    }
    
    bool addCar(int carType) {
        if (arr[carType] == 0) return false;
        --arr[carType];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */