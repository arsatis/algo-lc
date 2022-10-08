class MaxStack {
    stack<pair<int, int>> stk;
    priority_queue<pair<int, int>> heap;
    unordered_set<int> removed;
    int cnt;

public:
    MaxStack() {
        ios_base::sync_with_stdio(0);
        cnt = 0;
    }

    void push(int x) {
        stk.push({x, cnt});
        heap.push({x, cnt});
        cnt++;
    }

    int pop() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        const pair<int, int> p = stk.top();
        stk.pop();
        removed.insert(p.second);
        return p.first;
    }

    int top() {
        while (removed.count(stk.top().second)) {
            stk.pop();
        }
        return stk.top().first;
    }

    int peekMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        return heap.top().first;
    }

    int popMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        
        const pair<int, int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */