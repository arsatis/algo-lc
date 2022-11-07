class SeatManager {
    priority_queue<int, vector<int>, greater<int>> freeSeats;
    int nextSeat = 1;
public:
    SeatManager(int n) { }
    
    int reserve() {
        if (!freeSeats.empty()) {
            auto seat = freeSeats.top();
            freeSeats.pop();
            return seat;
        } else {
            return nextSeat++;
        } 
    }

    void unreserve(int seatNumber) {
        if (seatNumber < nextSeat) freeSeats.emplace(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
 
