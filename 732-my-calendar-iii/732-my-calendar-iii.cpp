class MyCalendarThree {
    map<int, int> books;
public:
    MyCalendarThree() {
        ios_base::sync_with_stdio(false);
    }
    
    int book(int start, int end) {
        ++books[start]; --books[end];
        int curr = 0, mx = 0;
        for (auto it = books.begin(); it != books.end(); ++it) {
            curr += it->second;
            mx = max(mx, curr);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */