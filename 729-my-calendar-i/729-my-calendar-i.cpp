class MyCalendar {
    map<int, int> books;
public:
    MyCalendar() {
        ios_base::sync_with_stdio(false);
    }
    
    bool book(int start, int end) {
        auto it = books.lower_bound(start);
        
        if (it != books.end()) {
            int left = max(start, it->first);
            int right = min(end, it->second);
            if (left < right) return false;
        }
        
        if (it != books.begin()) {
            it--;
            int left = max(start, it->first);
            int right = min(end, it->second);
            if (left < right) return false;
            it++;
        }
        
        books[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */