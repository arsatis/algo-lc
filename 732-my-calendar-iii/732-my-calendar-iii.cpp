class MyCalendarThree {
    map<int, int> counts;
    int mx = 0;
public:
    MyCalendarThree() {
        ios_base::sync_with_stdio(false);
        counts[INT_MIN] = 0;
        counts[INT_MAX] = 0;
        mx = 0;
    }
    
    int book(int start, int end) {
        auto l = prev(counts.upper_bound(start));   // l->first < start
        auto r = counts.lower_bound(end);           // r->first >= end
        
        for (auto curr = l, next = curr; curr != r; curr = next) {
            ++next;
            if (next->first > end) counts[end] = curr->second;
            if (curr->first <= start && next->first > start) mx = max(mx, counts[start] = curr->second + 1);            
            else mx = max(mx, ++curr->second);
        }
        
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */