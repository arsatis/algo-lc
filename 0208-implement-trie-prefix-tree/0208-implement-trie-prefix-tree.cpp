class Trie {
    struct TrieNode {
        bool isEnd;
        char val;
        unordered_map<char, TrieNode*> children;
        
        TrieNode() : isEnd(false), val(' ') {}
        TrieNode(char c) : isEnd(false), val('c') {}
        void setEnd() { isEnd = true; }
    };
    TrieNode* root;
public:
    Trie() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode(c);
            curr = curr->children[c];
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */