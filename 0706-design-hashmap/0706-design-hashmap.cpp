#define N 199997

class MyHashMap {
    int hm[N];
public:
    MyHashMap() {
        memset(hm, -1, sizeof(hm));
    }
    
    void put(int key, int value) {
        hm[key % N] = value;
    }
    
    int get(int key) {
        return hm[key % N];
    }
    
    void remove(int key) {
        hm[key % N] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 
