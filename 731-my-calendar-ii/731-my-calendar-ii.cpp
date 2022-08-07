class MyCalendarTwo {
    vector<pair<int, int>> overlap, calendar;
public:
    MyCalendarTwo() {
        ios_base::sync_with_stdio(false);
    }
    
    bool book(int start, int end) {
        for (auto &date : overlap)
            if (start < date.second && end > date.first)
                return false;
        for (auto &date : calendar)
            if (start < date.second && end > date.first)
                overlap.emplace_back(max(start, date.first), min(end, date.second));
        calendar.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */