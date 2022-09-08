class Solution {
public:
    string interpret(string command) {
        ios_base::sync_with_stdio(0);
        
        string s = "";
        auto it = command.begin();
        
        while (it != command.end()) {
            auto it2 = find(it, command.end(), '(');
            for (int i = 0; i < it2 - it; ++i) s += 'G';
            if (it2 == command.end()) break;
            
            it = find(it2, command.end(), ')');
            if (it++ - it2 == 1) s += 'o';
            else s += "al";
        }
        return s;
    }
};