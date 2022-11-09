class StockSpanner {
    stack<pair<int, int>> stocks;
public:
    StockSpanner() { }
    
    int next(int price) {
        int span = 1;
        while (!stocks.empty() && stocks.top().first <= price)
            span += stocks.top().second, stocks.pop();
        stocks.emplace(price, span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
