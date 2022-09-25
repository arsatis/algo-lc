class MyCircularQueue {
    vector<int> buffer;
    int front, back;
public:
    MyCircularQueue(int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        buffer.resize(k, -1);
        front = 0;
        back = 0;
    }
    
    bool enQueue(int value) {
        if (buffer[back] != -1) return false;
        buffer[back++] = value;
        if (back == buffer.size()) back = 0;
        return true;
    }
    
    bool deQueue() {
        if (buffer[front] == -1) return false;
        int tmp = buffer[front];
        buffer[front++] = -1;
        if (front == buffer.size()) front = 0;
        return true;
    }
    
    int Front() {
        return buffer[front];
    }
    
    int Rear() {
        int idx = back == 0 ? buffer.size() - 1 : back - 1;
        return buffer[idx];
    }
    
    bool isEmpty() {
        return buffer[front] == -1;
    }
    
    bool isFull() {
        return buffer[back] != -1;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */