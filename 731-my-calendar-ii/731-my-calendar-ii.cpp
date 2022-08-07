class MyCalendarTwo {
    map<int, int> books;
public:
    MyCalendarTwo() {
        ios_base::sync_with_stdio(false);
    }
    
    bool book(int start, int end) {
        ++books[start]; --books[end];
        int booked = 0;
        for (auto it = books.begin(); it != books.end(); ++it) {
            booked += it->second;
            if (booked >= 3) {
                --books[start]; ++books[end];
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */