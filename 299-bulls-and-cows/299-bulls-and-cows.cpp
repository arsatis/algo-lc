class Solution {
public:
    string getHint(string secret, string guess) {
        int chars[10] = { 0 };
        int bulls = 0, cows = 0;
        
        for (char c : secret) ++chars[c - '0'];
        for (char c : guess)
            if (chars[c - '0'] > 0) --chars[c - '0'], ++cows;
        for (int i = 0; i < secret.size(); ++i)
            if (secret[i] == guess[i]) ++bulls, --cows;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};