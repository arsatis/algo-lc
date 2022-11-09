class MyLinkedList {
    vector<int> ll;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        return index < ll.size() ? ll[index] : -1;
    }
    
    void addAtHead(int val) {
        ll.insert(ll.begin(), val);
    }
    
    void addAtTail(int val) {
        ll.emplace_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > ll.size()) return;
        ll.insert(ll.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if (index < ll.size()) ll.erase(ll.begin() + index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
