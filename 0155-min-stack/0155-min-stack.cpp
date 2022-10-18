class MinStack {
    stack<int> st;
    stack<pair<int, int>> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.emplace(val);
        if (!minst.empty() && val >= minst.top().first) ++minst.top().second;
        else minst.emplace(val, 1);
    }
    
    void pop() {
        st.pop();
        if (!minst.empty() && minst.top().second > 1) --minst.top().second;
        else minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */