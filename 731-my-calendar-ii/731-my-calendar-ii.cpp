class MyCalendarTwo {
    vector<pair<int, int>> o, c;
public:
    MyCalendarTwo() {
        ios_base::sync_with_stdio(false);
    }
    
    bool book(int start, int end) {
        for (auto &date : o)
            if (start < date.second && end > date.first)
                return false;
        
        for (auto &date : c)
            if (start < date.second && end > date.first)
                o.emplace_back(max(start, date.first), min(end, date.second));
        
        c.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */