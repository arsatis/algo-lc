class MaxStack {
    map<int, vector<list<int>::iterator>> by_val;
    list<int> stack;
    
    void EraseByIter(map<int, vector<list<int>::iterator>>::iterator it)
    {
        it->second.pop_back();
        if(it->second.empty())
        {
            by_val.erase(it);
        }
    }
    
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        auto it = prev(stack.end());
        by_val[x].push_back(it);
    }
    
    int pop() {
        int x = stack.back();
        stack.pop_back();
        EraseByIter(by_val.find(x));
        return x;
    }
    
    int top() {
       return stack.back();
    }
    
    int peekMax() {
        return by_val.rbegin()->first;
    }
    
    int popMax() {
        auto it_map = prev(by_val.end());
        int x = it_map->first;
        auto it_list = it_map->second.back();
        
        EraseByIter(it_map);
        stack.erase(it_list);
        return x;
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